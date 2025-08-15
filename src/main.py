def send_email(to, subject, body=None, cc=None, bcc=None, attachments=None):
    print(f"Sending email to: {to}")
    print(f"Subject: {subject}")
    if body:
        print(f"Body: {body}")
    if cc:
        print(f"CC: {cc}")
    if bcc:
        print(f"BCC: {bcc}")
    if attachments:
        print(f"Attachments: {attachments}")

# Usage:
send_email(
    "user@example.com",
    "Meeting Reminder",
    body="Don't forget our meeting at 10 AM.",
    cc=["manager@example.com"],
    attachments=["agenda.pdf"]
)

print()

send_email(
    "user@example.com",
    "Meeting Reminder",
    body="Don't forget our meeting at 10 AM.",
)
