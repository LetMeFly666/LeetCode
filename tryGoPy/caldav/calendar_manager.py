#!/usr/bin/env python3
"""
CalDAV Calendar Manager
Provides methods to read and modify calendars by ID
"""
import caldav
import logging
from pathlib import Path
from datetime import datetime
from typing import Optional, Dict, List, Tuple
import re

# Setup logging
log_dir = Path(__file__).parent / "logs"
log_dir.mkdir(exist_ok=True)
log_file = log_dir / f"calendar_manager_{datetime.now().strftime('%Y%m%d_%H%M%S')}.log"

logging.basicConfig(
    level=logging.INFO,
    format='%(asctime)s - %(levelname)s - %(message)s',
    handlers=[
        logging.FileHandler(log_file),
        logging.StreamHandler()
    ]
)
logger = logging.getLogger(__name__)


def load_credentials():
    """Load CalDAV credentials from secrets folder"""
    secrets_dir = Path(__file__).parent / "secrets"
    
    url = (secrets_dir / "caldav.url").read_text().strip()
    username = (secrets_dir / "caldav.username").read_text().strip()
    password = (secrets_dir / "caldav.password").read_text().strip()
    
    return url, username, password


def get_client():
    """Get authenticated CalDAV client"""
    url, username, password = load_credentials()
    logger.info(f"Connecting to CalDAV server: {url}")
    client = caldav.DAVClient(url=url, username=username, password=password)
    principal = client.principal()
    logger.info("Successfully authenticated to CalDAV server")
    return client, principal


def find_calendar_by_id(calendar_id: str) -> Optional[caldav.Calendar]:
    """
    Find a calendar by its ID or display name
    
    Args:
        calendar_id: The calendar ID or display name
        
    Returns:
        Calendar object if found, None otherwise
    """
    logger.info(f"Searching for calendar with ID/name: {calendar_id}")
    
    try:
        _, principal = get_client()
        calendars = principal.calendars()
        
        # First pass: exact match
        for cal in calendars:
            cal_id = cal.id or ""
            cal_name = cal.get_display_name() or ""
            
            logger.info(f"Found calendar - ID: {cal_id}, Name: {cal_name}")
            
            if calendar_id.lower() == cal_id.lower() or calendar_id.lower() == cal_name.lower():
                logger.info(f"Matched calendar (exact): {cal_name} (ID: {cal_id})")
                return cal
        
        # Second pass: partial match (only if no exact match found)
        for cal in calendars:
            cal_id = cal.id or ""
            cal_name = cal.get_display_name() or ""
            
            if calendar_id.lower() in cal_id.lower() or calendar_id.lower() in cal_name.lower():
                logger.info(f"Matched calendar (partial): {cal_name} (ID: {cal_id})")
                return cal
        
        logger.warning(f"Calendar '{calendar_id}' not found")
        return None
        
    except Exception as e:
        logger.error(f"Error finding calendar: {e}", exc_info=True)
        return None


def find_event_by_uid(event_uid: str) -> Optional[Tuple[caldav.Calendar, dict]]:
    """
    Find an event by its UID across all calendars
    
    Args:
        event_uid: The event UID to search for
        
    Returns:
        Tuple of (Calendar, event_info) if found, None otherwise
    """
    logger.info(f"Searching for event with UID: {event_uid}")
    
    try:
        _, principal = get_client()
        calendars = principal.calendars()
        
        for cal in calendars:
            cal_name = cal.get_display_name()
            events = cal.events()
            
            for event in events:
                event_data = event.data
                
                # Extract UID
                event_uid_in_data = None
                summary = None
                rrule = None
                
                for line in event_data.split('\n'):
                    if line.startswith('UID:'):
                        event_uid_in_data = line.replace('UID:', '').strip()
                    elif line.startswith('SUMMARY:'):
                        summary = line.replace('SUMMARY:', '').strip()
                    elif line.startswith('RRULE:'):
                        rrule = line.replace('RRULE:', '').strip()
                
                if event_uid.lower() in (event_uid_in_data or "").lower():
                    logger.info(f"Found event in calendar: {cal_name}")
                    logger.info(f"  UID: {event_uid_in_data}")
                    logger.info(f"  Summary: {summary}")
                    if rrule:
                        logger.info(f"  RRULE: {rrule}")
                    
                    event_info = {
                        'uid': event_uid_in_data,
                        'summary': summary,
                        'rrule': rrule,
                        'url': str(event.url),
                        'has_repeat': rrule is not None,
                        'repeat_never_ends': is_repeat_never_ends(rrule) if rrule else False,
                        'calendar_name': cal_name,
                        'event_obj': event
                    }
                    
                    return cal, event_info
        
        logger.warning(f"Event '{event_uid}' not found")
        return None
        
    except Exception as e:
        logger.error(f"Error finding event: {e}", exc_info=True)
        return None


def is_repeat_never_ends(rrule_str: str) -> bool:
    """
    Check if a recurrence rule (RRULE) means "repeat forever" (never ends)
    
    A repeat never ends if:
    - No COUNT parameter (which would limit occurrences)
    - No UNTIL parameter (which would limit by date)
    
    Args:
        rrule_str: RRULE string (e.g., "FREQ=DAILY;INTERVAL=1")
        
    Returns:
        True if repeat has no end (forever), False if it has a limit
    """
    logger.info(f"Checking if repeat never ends: {rrule_str}")
    
    # Check for COUNT or UNTIL parameters
    has_count = "COUNT=" in rrule_str.upper()
    has_until = "UNTIL=" in rrule_str.upper()
    
    never_ends = not (has_count or has_until)
    
    logger.info(f"  Has COUNT: {has_count}, Has UNTIL: {has_until}")
    logger.info(f"  Result - Never ends (forever): {never_ends}")
    
    return never_ends


def get_event_rrule(event_data: str) -> Optional[str]:
    """
    Extract RRULE from event data (iCalendar format)
    
    Args:
        event_data: Raw event data in iCalendar format
        
    Returns:
        RRULE string if found, None otherwise
    """
    for line in event_data.split('\n'):
        if line.startswith('RRULE'):
            return line.replace('RRULE:', '').strip()
    return None


def get_calendar_events(calendar_id: str, include_repeat_only: bool = False) -> List[Dict]:
    """
    Get all events from a calendar
    
    Args:
        calendar_id: The calendar UUID or display name
        include_repeat_only: If True, only return events with recurrence rules
        
    Returns:
        List of event dictionaries with details
    """
    logger.info(f"Retrieving events from calendar: {calendar_id}")
    
    try:
        calendar = find_calendar_by_id(calendar_id)
        if not calendar:
            logger.warning(f"Calendar not found: {calendar_id}")
            return []
        
        events = calendar.events()
        logger.info(f"Found {len(events)} total events")
        
        event_list = []
        for event in events:
            try:
                event_data = event.data
                
                # Extract summary
                summary = "No title"
                for line in event_data.split('\n'):
                    if line.startswith('SUMMARY:'):
                        summary = line.replace('SUMMARY:', '').strip()
                        break
                
                # Extract RRULE
                rrule = get_event_rrule(event_data)
                
                # Skip if include_repeat_only is True and no RRULE
                if include_repeat_only and not rrule:
                    continue
                
                event_info = {
                    'summary': summary,
                    'rrule': rrule,
                    'url': str(event.url),
                    'has_repeat': rrule is not None,
                    'repeat_never_ends': is_repeat_never_ends(rrule) if rrule else False
                }
                
                event_list.append(event_info)
                logger.info(f"Event: {summary}")
                if rrule:
                    logger.info(f"  RRULE: {rrule}")
                    logger.info(f"  Never ends: {event_info['repeat_never_ends']}")
                    
            except Exception as e:
                logger.warning(f"Error processing event: {e}")
                continue
        
        logger.info(f"Retrieved {len(event_list)} events")
        return event_list
        
    except Exception as e:
        logger.error(f"Error retrieving calendar events: {e}", exc_info=True)
        return []


def modify_calendar_event(calendar_id: str, event_summary: str, new_rrule: Optional[str] = None, 
                          new_summary: Optional[str] = None) -> bool:
    """
    Modify an event in a calendar
    
    Args:
        calendar_id: The calendar UUID or display name
        event_summary: The current summary (title) of the event to modify
        new_rrule: New RRULE to set (if None, removes recurrence)
        new_summary: New summary/title for the event
        
    Returns:
        True if modification successful, False otherwise
    """
    logger.info(f"Modifying event '{event_summary}' in calendar: {calendar_id}")
    
    try:
        calendar = find_calendar_by_id(calendar_id)
        if not calendar:
            logger.warning(f"Calendar not found: {calendar_id}")
            return False
        
        events = calendar.events()
        
        for event in events:
            event_data = event.data
            
            # Find the matching event
            current_summary = None
            for line in event_data.split('\n'):
                if line.startswith('SUMMARY:'):
                    current_summary = line.replace('SUMMARY:', '').strip()
                    break
            
            if current_summary != event_summary:
                continue
            
            logger.info(f"Found event to modify: {current_summary}")
            
            # Modify the event data
            modified_data = event_data
            
            # Update summary if provided
            if new_summary:
                old_summary_line = f"SUMMARY:{current_summary}"
                new_summary_line = f"SUMMARY:{new_summary}"
                modified_data = modified_data.replace(old_summary_line, new_summary_line)
                logger.info(f"Updated summary to: {new_summary}")
            
            # Update or remove RRULE
            if new_rrule is not None:
                # Remove existing RRULE
                modified_data = re.sub(r'RRULE:[^\n]*\n?', '', modified_data)
                # Add new RRULE
                modified_data = modified_data.replace('SUMMARY:', f'RRULE:{new_rrule}\nSUMMARY:', 1)
                logger.info(f"Updated RRULE to: {new_rrule}")
            else:
                # Remove RRULE if new_rrule is explicitly None
                modified_data = re.sub(r'RRULE:[^\n]*\n?', '', modified_data)
                logger.info("Removed recurrence rule (RRULE)")
            
            # Save modifications
            event.data = modified_data
            event.save()
            logger.info("Event successfully modified and saved")
            
            return True
        
        logger.warning(f"Event '{event_summary}' not found in calendar")
        return False
        
    except Exception as e:
        logger.error(f"Error modifying calendar event: {e}", exc_info=True)
        return False


def check_calendar_repeat_status(calendar_id: str) -> Tuple[bool, List[Dict]]:
    """
    Check all repeat events in a calendar and their "never ends" status
    
    Args:
        calendar_id: The calendar UUID or display name
        
    Returns:
        Tuple of (has_never_ending_repeats, list_of_repeat_events)
    """
    logger.info(f"Checking repeat status for calendar: {calendar_id}")
    
    events = get_calendar_events(calendar_id, include_repeat_only=True)
    
    repeat_events = []
    has_never_ending = False
    
    for event in events:
        if event['rrule']:
            repeat_events.append({
                'summary': event['summary'],
                'rrule': event['rrule'],
                'never_ends': event['repeat_never_ends']
            })
            if event['repeat_never_ends']:
                has_never_ending = True
                logger.info(f"Found repeat event that never ends: {event['summary']}")
            else:
                logger.info(f"Found repeat event with end date/count: {event['summary']}")
    
    logger.info(f"Calendar has {len(repeat_events)} repeat events, {has_never_ending} never end")
    
    return has_never_ending, repeat_events


def main():
    """Example usage and testing"""
    logger.info("=" * 70)
    logger.info("CalDAV Calendar Manager")
    logger.info("=" * 70)
    
    # Example 1: Check the specific calendar ID
    calendar_id = "6A3AD2E1-C742-4158-9C0D-1D8BA5BB41C0"
    
    logger.info("\n" + "=" * 70)
    logger.info(f"Example 1: Checking event UID: {calendar_id}")
    logger.info("=" * 70)
    
    result = find_event_by_uid(calendar_id)
    if result:
        cal, event_info = result
        logger.info("\nEvent found!")
        logger.info(f"  Calendar: {event_info['calendar_name']}")
        logger.info(f"  UID: {event_info['uid']}")
        logger.info(f"  Summary: {event_info['summary']}")
        logger.info(f"  Has repeat: {event_info['has_repeat']}")
        if event_info['rrule']:
            logger.info(f"  RRULE: {event_info['rrule']}")
            logger.info(f"  Repeat never ends: {event_info['repeat_never_ends']}")
    else:
        logger.info(f"\nEvent '{calendar_id}' not found in any calendar")
    
    # Example 2: List all repeat events in "背单词" calendar
    logger.info("\n" + "=" * 70)
    logger.info("Example 2: Checking '背单词' calendar for repeat events")
    logger.info("=" * 70)
    
    has_never_ending, repeat_events = check_calendar_repeat_status("背单词")
    
    logger.info(f"\nCalendar '背单词' status:")
    logger.info(f"  - Has repeat events that never end: {has_never_ending}")
    logger.info(f"  - Total repeat events: {len(repeat_events)}")
    
    if repeat_events:
        logger.info("\nRepeat events details:")
        for i, event in enumerate(repeat_events, 1):
            logger.info(f"\n  [{i}] {event['summary']}")
            logger.info(f"      RRULE: {event['rrule']}")
            logger.info(f"      Never ends: {event['never_ends']}")
    
    logger.info("\n" + "=" * 70)
    logger.info(f"Log saved to: {log_file}")
    logger.info("=" * 70)


if __name__ == "__main__":
    main()
