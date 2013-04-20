cimport cmdpython

cdef public cmd_entry cmd_entry_python

# We need with gil because were being called as a function pointer
# from C code that has embeded python itself. Therefore no gil state
# has been aquired yet!
cdef cmd_retval python_exec (cmd * cmd, cmd_q * cmdq) with gil:
    cdef char * message = "Inside your python command inside tmux!!!"
    log_debug (message)
    return CMD_RETURN_NORMAL;

cdef public void tmux_init_cython () with gil:
    cmd_entry_python.name = "python"
    cmd_entry_python.alias = "py"
    cmd_entry_python.args_template = ""
    cmd_entry_python.args_lower = 0
    cmd_entry_python.args_upper = 0
    cmd_entry_python.usage = "python usage..."
    cmd_entry_python.flags = 0
    #cmd_entry_python.key_binding = NULL
    #cmd_entry_python.check = NULL
    cmd_entry_python.execc = python_exec
