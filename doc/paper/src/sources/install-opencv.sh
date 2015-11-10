sudo su
# cp /media/sf_share/opencv.zip /home/user/nao/devtools
# exit

# Berechtigungen für das ZIP ändern
unzip opencv.zip # dann umbenennen in "OpenCV" (Ordner)
cd OpenCV
mkdir build
cd build
cmake -D WITH_QT=ON -D WITH_XINE=ON -D WITH_OPENGL=ON -D WITH_TBB=ON -D BUILD_EXAMPLES=ON ..
# Alternativ kann '-D BUILD_EXAMPLES=ON' ausgelassen werden
make # Eventuell mit -j<n> auf Mehrkernsystemen
sudo vim /etc/ld.so.conf
sudo ldconfig
