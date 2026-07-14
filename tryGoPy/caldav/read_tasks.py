#!/usr/bin/env python3
"""
CalDAV task reader agent
Reads repeat tasks from the "背单词" calendar
"""
import sys
from pathlib import Path

import caldav
import logging
from datetime import datetime

# Setup logging
log_dir = Path(__file__).parent / "logs"
log_dir.mkdir(exist_ok=True)
log_file = log_dir / f"task_reader_{datetime.now().strftime('%Y%m%d_%H%M%S')}.log"

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

def read_repeat_tasks():
    """Read repeat tasks from 背单词 calendar"""
    logger.info("Starting to read repeat tasks from 背单词 calendar")
    
    try:
        url, username, password = load_credentials()
        logger.info(f"Connecting to CalDAV server: {url}")
        
        # Connect to CalDAV server
        client = caldav.DAVClient(url=url, username=username, password=password)
        principal = client.principal()
        logger.info("Successfully authenticated to CalDAV server")
        
        # Get all calendars
        calendars = principal.calendars()
        logger.info(f"Found {len(calendars)} calendars")
        
        # Find the "背单词" calendar
        target_calendar = None
        for cal in calendars:
            cal_name = cal.get_display_name() or ""
            logger.info(f"Calendar: {cal_name}")
            if "背单词" in cal_name:
                target_calendar = cal
                logger.info(f"Found target calendar: {cal_name}")
                break
        
        if not target_calendar:
            logger.warning("Calendar '背单词' not found")
            return []
        
        # Read tasks/events from the calendar
        events = target_calendar.events()
        logger.info(f"Found {len(events)} total events")
        
        repeat_tasks = []
        for event in events:
            try:
                event_data = event.data
                
                # Extract summary
                summary = "No title"
                if "SUMMARY:" in event_data:
                    for line in event_data.split('\n'):
                        if line.startswith('SUMMARY:'):
                            summary = line.replace('SUMMARY:', '').strip()
                            break
                
                # Check for RRULE (repeat rule)
                if "RRULE" in event_data:
                    # Extract RRULE line
                    rrule = None
                    for line in event_data.split('\n'):
                        if line.startswith('RRULE'):
                            rrule = line.replace('RRULE:', '').strip()
                            break
                    
                    if rrule:
                        repeat_tasks.append({
                            'summary': summary,
                            'rrule': rrule,
                            'url': str(event.url)
                        })
                        logger.info(f"Repeat task: {summary} (rrule: {rrule})")
            except Exception as e:
                logger.warning(f"Error processing event: {e}")
                continue
        
        logger.info(f"Found {len(repeat_tasks)} repeat tasks")
        return repeat_tasks
        
    except Exception as e:
        logger.error(f"Error reading repeat tasks: {e}", exc_info=True)
        return []

def main():
    """Main entry point"""
    logger.info("=" * 60)
    logger.info("CalDAV Repeat Task Reader Agent")
    logger.info("=" * 60)
    
    repeat_tasks = read_repeat_tasks()
    
    # Save results to log
    logger.info("=" * 60)
    logger.info(f"Task Summary: Found {len(repeat_tasks)} repeat tasks")
    logger.info("=" * 60)
    
    for i, task in enumerate(repeat_tasks, 1):
        logger.info(f"\n[{i}] {task['summary']}")
        logger.info(f"    Recurrence: {task['rrule']}")
    
    logger.info("\nLog saved to: " + str(log_file))
    return len(repeat_tasks)

if __name__ == "__main__":
    result = main()
    sys.exit(0 if result >= 0 else 1)
