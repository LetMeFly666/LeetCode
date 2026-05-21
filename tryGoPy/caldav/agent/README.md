# CalDAV Task Reader Agent

## Overview
Python agent for reading repeat tasks from the "背单词" (Word Memorization) calendar via CalDAV protocol.

## Features
- Connects to CalDAV server using credentials from `secrets/` folder
- Lists all available calendars
- Finds and filters the "背单词" calendar
- Extracts repeat tasks (events with recurrence rules)
- Logs all operations to `logs/` folder with timestamped log files
- Does not read credentials directly from code (uses environment-based loading)

## Usage

### Setup
```bash
# Create and activate virtual environment
python3 -m venv venv
source venv/bin/activate  # macOS/Linux
# or: venv\Scripts\activate  # Windows

# Install dependencies
pip install caldav
```

### Run
```bash
# From caldav directory
source venv/bin/activate
python3 read_tasks.py
```

## Output
- Console output with task information
- Detailed logs saved to `logs/task_reader_YYYYMMDD_HHMMSS.log`

## Dependencies
- `caldav`: Python CalDAV client library

## Credentials Required
Create the following files in `secrets/` folder:
- `caldav.url` - CalDAV server URL
- `caldav.username` - Username for authentication
- `caldav.password` - Password for authentication

## Project Structure
```
caldav/
├── read_tasks.py          # Main agent script
├── agent/                 # Agent documentation
│   └── README.md         # This file
├── secrets/              # Credentials (not committed)
│   ├── caldav.url
│   ├── caldav.username
│   └── caldav.password
├── logs/                 # Log files (not committed)
├── venv/                 # Virtual environment (not committed)
└── .gitignore            # Excludes venv/, logs/, secrets/
```
