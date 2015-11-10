sudo su
# cp /media/share/TicTacToe /home/user/nao/workspace/
# exit
cd ~/nao/workspace
mv TicTacToe tictactoe
cd tictactoe && mv Code/* .  && rmdir Code
qibuild configure -c test-001


