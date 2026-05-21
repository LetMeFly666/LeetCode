# Project Memory & Knowledge Base

## Project Overview
**CalDAV Task Reader Agent** - Reads recurring tasks from Nextcloud CalDAV server

**Target**: "背单词" (Word Memorization) calendar
**Purpose**: Extract and log all repeat/recurring tasks for tracking

---

## Architecture Understanding

### Technology Stack
- **Protocol**: CalDAV (CalDAV protocol for calendar data)
- **Server**: Nextcloud (LetMeFly: HIDDEN! URL)
- **Library**: caldav 2.0+ Python library
- **Data Format**: iCalendar (ICS/VCALENDAR)

### Data Flow
```
CalDAV Server
    ↓ (authenticated via secrets/)
Client connects (caldav library)
    ↓
List all calendars (7 total)
    ↓
Filter for "背单词" calendar
    ↓
Fetch all events (currently: 1 event)
    ↓
Parse iCalendar data
    ↓
Extract repeat tasks (RRULE detection)
    ↓
Log results to files
```

---

## Key Technical Insights

### CalDAV API Notes
- **Authentication**: Basic auth (username + password)
- **Calendars**: Returned as list of Calendar objects
- **Display Name**: Use `cal.get_display_name()` (not deprecated `cal.name`)
- **Events**: Accessed via `cal.events()` method
- **Event Data**: Available as raw iCalendar string via `event.data`

### iCalendar Format (VCALENDAR)
```
BEGIN:VCALENDAR
  PRODID:-//Apple Inc.//iPhone OS 26.2//EN
  VERSION:2.0
  BEGIN:VTIMEZONE
    ... (timezone definition)
  END:VTIMEZONE
  BEGIN:VEVENT
    SUMMARY:Task title
    DTSTART;TZID=...:20260121T230917
    DTEND;TZID=...:20260121T230920
    RRULE:FREQ=YEARLY;UNTIL=19910914T170000Z;BYMONTH=9;BYDAY=3SU
    UID:DA640753-2A56-4DB0-91BD-094374BDBAD6
    ... (other properties)
  END:VEVENT
END:VCALENDAR
```

### Repeat Rule (RRULE) Format
- `FREQ`: Frequency (DAILY, WEEKLY, MONTHLY, YEARLY)
- `UNTIL`: Until date (exclusive)
- `BYMONTH`: Month restriction (1-12)
- `BYDAY`: Day of week restriction (MO, TU, WE, TH, FR, SA, SU with optional week number)

**Current Task RRULE**:
```
FREQ=YEARLY;UNTIL=19910914T170000Z;BYMONTH=9;BYDAY=3SU
= Yearly repeat, until Sep 14, 1991, in September, on 3rd Sunday
(NOTE: This RRULE is historical/deprecated - UNTIL date is in the past)
```

---

## API Design Decisions

### Why Raw iCalendar Parsing Over vobject?
- **Reason 1**: caldav 2.0 removed vobject as official dependency
- **Reason 2**: vobject parsing was unreliable (returned None)
- **Reason 3**: Raw parsing is simpler and more transparent
- **Trade-off**: Less structured data, but more reliable

### Error Handling Strategy
- Log all errors to file (not just console)
- Continue processing on individual event failures
- Report summary with total count
- Preserve raw event data for debugging

---

## Credentials & Security

### Secret Files (DO NOT READ)
- `secrets/caldav.url` → CalDAV server endpoint
- `secrets/caldav.username` → Authentication username
- `secrets/caldav.password` → Authentication password

### Security Practice
✅ Credentials loaded at runtime (not in code)
✅ Virtual environment isolates dependencies
✅ Logs don't include sensitive data
✅ .gitignore excludes secrets/

---

## Current State

### Successfully Detected
- ✅ 1 repeat task: "背单词+英语小听力"
- ✅ RRULE extraction working
- ✅ Logging to timestamped files
- ✅ Connection to CalDAV server stable

### Limitations
- Current RRULE is historical (UNTIL date in past)
- Only 1 event in calendar currently
- No filtering by date or status
- No event modification capability (read-only)

---

## Lessons Learned

1. **Deprecation Management**: caldav library updates removed dependencies
   - Always check changelog when errors occur with new versions
   - Fallback to raw data parsing when libraries fail

2. **iCalendar Complexity**: Parsing VCALENDAR requires timezone awareness
   - DateTime formatting uses TZID references
   - Multiple formats for dates (DTSTART;TZID= vs DTSTART=)

3. **Network Timeouts**: CalDAV operations are network-dependent
   - Connection time: ~6 seconds
   - May need retry logic for production use

4. **Calendar Discovery**: Multiple calendars available
   - Need to filter by name (string matching)
   - Display names are more reliable than IDs

---

## Code Patterns to Remember

### Loading Secrets Safely
```python
def load_credentials():
    secrets_dir = Path("secrets")
    url = (secrets_dir / "caldav.url").read_text().strip()
    username = (secrets_dir / "caldav.username").read_text().strip()
    password = (secrets_dir / "caldav.password").read_text().strip()
    return url, username, password
```

### CalDAV Connection Pattern
```python
client = caldav.DAVClient(url=url, username=username, password=password)
principal = client.principal()
calendars = principal.calendars()
for cal in calendars:
    if search_name in cal.get_display_name():
        events = cal.events()
```

### RRULE Extraction Pattern
```python
for line in event.data.split('\n'):
    if line.startswith('RRULE'):
        rrule = line.replace('RRULE:', '').strip()
        # Process rrule...
```

---

## Dependencies & Versions

- `caldav` - CalDAV client library
- `vobject` - iCalendar object serialization (installed but not used in current version)
- Python 3.7+

### Installation
```bash
pip install caldav vobject
```

---

## Future Enhancement Ideas

1. **Multi-Calendar Support**: Read from multiple calendars
2. **Export Functionality**: JSON, CSV export options
3. **Caching Layer**: Store calendar data locally
4. **Event Creation**: Add tasks to calendar programmatically
5. **Recurring Expansion**: Expand RRULE into actual dates
6. **Scheduling**: Cron job wrapper for periodic updates
