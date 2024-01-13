cmd_/home/pxy/OS/module1/module1.mod := printf '%s\n'   module1.o | awk '!x[$$0]++ { print("/home/pxy/OS/module1/"$$0) }' > /home/pxy/OS/module1/module1.mod
