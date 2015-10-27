cd ~/nao/workspace
qibuild init
mkdir project
qisrc add .
qibuild config --wizard
# Auswahl:
#
# 1) Unix-Makefiles
# 2) No IDE
#
# Evtl. weitere Anfragen entsprechend bestätigen
#
qibuild add-config "test-001"

