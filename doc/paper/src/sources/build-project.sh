# in ~/nao/workspace/tictactoe
qisrc add . -c "toolchain-name"
qibuild config --wizard
# Auswahl:
#
# 1) Unix-Makefiles
# 2) No IDE
#
# Evtl. weitere Anfragen entsprechend bestätigen
#
qibuild add-config "toolchain-name" -t "toolchain-name"
qibuild configure -c "toolchain-name"
qibuild make -c "toolchain-name"
qibuild open -c "toolchain-name"
