/*
  File autogenerated by gengetopt version 2.11
  generated with the following command:
  /usr/bin/gengetopt --input ./cmdline.sh 

  The developers of gengetopt consider the fixed text that goes in all
  gengetopt output files to be in the public domain:
  we make no copyright claims on it.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* If we use autoconf.  */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "getopt.h"

#include "cmdline.h"

void
cmdline_parser_print_version (void)
{
  printf ("%s %s\n", CMDLINE_PARSER_PACKAGE, CMDLINE_PARSER_VERSION);
}

void
cmdline_parser_print_help (void)
{
  cmdline_parser_print_version ();
  printf("\n"
  "Purpose:\n"
  "  The Ganglia Monitoring Daemon (gmond) listens to the cluster\n"
  "  message channel, stores the data in-memory and when requested\n"
  "  will output an XML description of the state of the cluster\n"
  "\n"
  "Usage: %s [OPTIONS]...\n", CMDLINE_PARSER_PACKAGE);
  printf("\n");
  printf("  -h, --help             Print help and exit\n");
  printf("  -V, --version          Print version and exit\n");
  printf("  -c, --conf=STRING      Location of gmond configuration file  (default=\n                           `/etc/gmond.conf')\n");
  printf("  -l, --location=STRING  Location of this host in the cluster \n                           'rack,rank,plane'.  (default=`0,0,0')\n");
  printf("  -d, --debug=INT        Debug level. If greater than zero, daemon will stay \n                           in foreground.  (default=`0')\n");
  printf("  -f, --foreground       Run in foreground (don't daemonize)  (default=off)\n");
  printf("  -t, --default_config   Print the default configuration to stdout and exit  \n                           (default=off)\n");
  printf("  -m, --metrics          Print the list of metrics this gmond supports  \n                           (default=off)\n");
  printf("  -b, --bandwidth        Calculate minimum bandwidth use for configuration  \n                           (default=off)\n");
  printf("  -r, --convert=STRING   Convert a 2.5.x configuration file to the new 2.6 \n                           format\n");
}


static char *gengetopt_strdup (const char *s);

/* gengetopt_strdup() */
/* strdup.c replacement of strdup, which is not standard */
char *
gengetopt_strdup (const char *s)
{
  char *result = (char*)malloc(strlen(s) + 1);
  if (result == (char*)0)
    return (char*)0;
  strcpy(result, s);
  return result;
}

int
cmdline_parser (int argc, char * const *argv, struct gengetopt_args_info *args_info)
{
  int c;	/* Character of the parsed option.  */
  int missing_required_options = 0;

  args_info->help_given = 0 ;
  args_info->version_given = 0 ;
  args_info->conf_given = 0 ;
  args_info->location_given = 0 ;
  args_info->debug_given = 0 ;
  args_info->foreground_given = 0 ;
  args_info->default_config_given = 0 ;
  args_info->metrics_given = 0 ;
  args_info->bandwidth_given = 0 ;
  args_info->convert_given = 0 ;
#define clear_args() { \
  args_info->conf_arg = gengetopt_strdup("/etc/gmond.conf") ;\
  args_info->location_arg = gengetopt_strdup("0,0,0") ;\
  args_info->debug_arg = 0 ;\
  args_info->foreground_flag = 0;\
  args_info->default_config_flag = 0;\
  args_info->metrics_flag = 0;\
  args_info->bandwidth_flag = 0;\
  args_info->convert_arg = NULL; \
}

  clear_args();

  optarg = 0;
  optind = 1;
  opterr = 1;
  optopt = '?';

  while (1)
    {
      int option_index = 0;
      char *stop_char;

      static struct option long_options[] = {
        { "help",	0, NULL, 'h' },
        { "version",	0, NULL, 'V' },
        { "conf",	1, NULL, 'c' },
        { "location",	1, NULL, 'l' },
        { "debug",	1, NULL, 'd' },
        { "foreground",	0, NULL, 'f' },
        { "default_config",	0, NULL, 't' },
        { "metrics",	0, NULL, 'm' },
        { "bandwidth",	0, NULL, 'b' },
        { "convert",	1, NULL, 'r' },
        { NULL,	0, NULL, 0 }
      };

      stop_char = 0;
      c = getopt_long (argc, argv, "hVc:l:d:ftmbr:", long_options, &option_index);

      if (c == -1) break;	/* Exit from `while (1)' loop.  */

      switch (c)
        {
        case 'h':	/* Print help and exit.  */
          clear_args ();
          cmdline_parser_print_help ();
          exit (EXIT_SUCCESS);

        case 'V':	/* Print version and exit.  */
          clear_args ();
          cmdline_parser_print_version ();
          exit (EXIT_SUCCESS);

        case 'c':	/* Location of gmond configuration file.  */
          if (args_info->conf_given)
            {
              fprintf (stderr, "%s: `--conf' (`-c') option given more than once\n", CMDLINE_PARSER_PACKAGE);
              clear_args ();
              exit (EXIT_FAILURE);
            }
          args_info->conf_given = 1;
          if (args_info->conf_arg)
            free (args_info->conf_arg); /* free default string */
          args_info->conf_arg = gengetopt_strdup (optarg);
          break;

        case 'l':	/* Location of this host in the cluster 'rack,rank,plane'..  */
          if (args_info->location_given)
            {
              fprintf (stderr, "%s: `--location' (`-l') option given more than once\n", CMDLINE_PARSER_PACKAGE);
              clear_args ();
              exit (EXIT_FAILURE);
            }
          args_info->location_given = 1;
          if (args_info->location_arg)
            free (args_info->location_arg); /* free default string */
          args_info->location_arg = gengetopt_strdup (optarg);
          break;

        case 'd':	/* Debug level. If greater than zero, daemon will stay in foreground..  */
          if (args_info->debug_given)
            {
              fprintf (stderr, "%s: `--debug' (`-d') option given more than once\n", CMDLINE_PARSER_PACKAGE);
              clear_args ();
              exit (EXIT_FAILURE);
            }
          args_info->debug_given = 1;
          args_info->debug_arg = strtol (optarg,&stop_char,0);
          break;

        case 'f':	/* Run in foreground (don't daemonize).  */
          if (args_info->foreground_given)
            {
              fprintf (stderr, "%s: `--foreground' (`-f') option given more than once\n", CMDLINE_PARSER_PACKAGE);
              clear_args ();
              exit (EXIT_FAILURE);
            }
          args_info->foreground_given = 1;
          args_info->foreground_flag = !(args_info->foreground_flag);
          break;

        case 't':	/* Print the default configuration to stdout and exit.  */
          if (args_info->default_config_given)
            {
              fprintf (stderr, "%s: `--default_config' (`-t') option given more than once\n", CMDLINE_PARSER_PACKAGE);
              clear_args ();
              exit (EXIT_FAILURE);
            }
          args_info->default_config_given = 1;
          args_info->default_config_flag = !(args_info->default_config_flag);
          break;

        case 'm':	/* Print the list of metrics this gmond supports.  */
          if (args_info->metrics_given)
            {
              fprintf (stderr, "%s: `--metrics' (`-m') option given more than once\n", CMDLINE_PARSER_PACKAGE);
              clear_args ();
              exit (EXIT_FAILURE);
            }
          args_info->metrics_given = 1;
          args_info->metrics_flag = !(args_info->metrics_flag);
          break;

        case 'b':	/* Calculate minimum bandwidth use for configuration.  */
          if (args_info->bandwidth_given)
            {
              fprintf (stderr, "%s: `--bandwidth' (`-b') option given more than once\n", CMDLINE_PARSER_PACKAGE);
              clear_args ();
              exit (EXIT_FAILURE);
            }
          args_info->bandwidth_given = 1;
          args_info->bandwidth_flag = !(args_info->bandwidth_flag);
          break;

        case 'r':	/* Convert a 2.5.x configuration file to the new 2.6 format.  */
          if (args_info->convert_given)
            {
              fprintf (stderr, "%s: `--convert' (`-r') option given more than once\n", CMDLINE_PARSER_PACKAGE);
              clear_args ();
              exit (EXIT_FAILURE);
            }
          args_info->convert_given = 1;
          args_info->convert_arg = gengetopt_strdup (optarg);
          break;


        case 0:	/* Long option with no short option */

        case '?':	/* Invalid option.  */
          /* `getopt_long' already printed an error message.  */
          exit (EXIT_FAILURE);

        default:	/* bug: option not considered.  */
          fprintf (stderr, "%s: option unknown: %c\n", CMDLINE_PARSER_PACKAGE, c);
          abort ();
        } /* switch */
    } /* while */


  if ( missing_required_options )
    exit (EXIT_FAILURE);

  return 0;
}
