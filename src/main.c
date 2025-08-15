#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char *from;
  char *body;
  char **cc;
  char **bcc;
  char **attachments;
} EmailOpt;

static void send_mail_(const char *to, const char *subject,
                       const EmailOpt opt) {
  if (opt.from != NULL) {
    printf("Sending email from: %s\n", opt.from);
  }

  printf("Sending email to:   %s\n", to);
  printf("Subject:            %s\n", subject);

  if (opt.body != NULL) {
    printf("Body: %s\n", opt.body);
  }

  if (opt.cc != NULL) {
    printf("cc: [ ");
    for (char **cc = opt.cc; *cc != NULL; cc++) {
      if (cc != opt.cc) {
        printf(", ");
      }

      printf("%s", *cc);
    }
    printf(" ]\n");
  }

  if (opt.bcc != NULL) {
  }

  if (opt.attachments != NULL) {
    printf("attachments: [ ");
    for (char **attachment = opt.attachments; *attachment != NULL;
         attachment++) {
      if (attachment != opt.attachments) {
        printf(", ");
      }

      printf("%s", *attachment);
    }
    printf(" ]\n");
  }
}

#define send_mail(TO, SUBJECT, ...)                                            \
  send_mail_((TO), (SUBJECT),                                                  \
             (EmailOpt){.from = "from@example.com", __VA_ARGS__})

int main(void) {
  send_mail("to@example.com", "Meeting reminder");

  printf("\n");

  send_mail("to@example.com", "Meeting reminder",
            .body = "Don't forget our meeting at 10 AM.",
            .cc = (char **)(char *[]){"manager@example.com", NULL},
            .attachments =
                (char **)(char *[]){"agenda.pdf", "schedule.pdf", NULL});

  printf("\n");

  send_mail("to@example.com", "Meeting reminder", .from = "user@example.com",
            .body = "Don't forget our meeting at 10 AM.",
            .cc = (char **)(char *[]){"manager@example.com", NULL},
            .attachments =
                (char **)(char *[]){"agenda.pdf", "schedule.pdf", NULL});

  return EXIT_SUCCESS;
}
