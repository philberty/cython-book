# PXD declarations for cmd-python cython
cdef extern from "tmux.h":

    cdef struct cmd:
        cmd_entry * entry
        args * aargs
        char * file
        int line

    cdef struct cmd_q:
        int refererences
        int dead
        void * client
        int client_exit
        int queue
        void * item
        cmd * cmd
        int time
        int number
        void (*emptyfn)(cmd_q *)
        void * msgdata

    cdef struct args:
        char * flags
        char **values
        int argc
        char **argv

    cdef enum cmd_retval:
        CMD_RETURN_ERROR = -1
        CMD_RETURN_NORMAL = 0
        CMD_RETURN_WAIT = 1
        CMD_RETURN_STOP = 2

    cdef struct cmd_entry:
        char * name
        char * alias
        char * args_template
        int args_lower
        int args_upper
        char * usage
        int flags
        void (*keybinding)(cmd *, int)
        int (*check)(args *)
        cmd_retval (*execc)(cmd *, cmd_q *)

    cdef void log_debug (char *)
