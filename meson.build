project('console_c','c')

libs = shared_library('interface','code/interface/interface.c', 'code/commands/commands.c', 'code/commands_repl_c/commands_repl.c', 'code/get_commands/get_commands.c' , 'code/repl_code/repl.c')
eo = libs.extract_objects('code/interface/interface.c', 'code/commands/commands.c', 'code/commands_repl_c/commands_repl.c', 'code/get_commands/get_commands.c' , 'code/repl_code/repl.c')

executable('main', 'main.c', objects: eo)