qmake untitled.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug
make
echo begin render video

./pictureToVideo render_SPA0_0deg.png video/render_SPA0_0deg.avi & 
./pictureToVideo render_SPA1_0deg.png video/render_SPA1_0deg.avi & 
./pictureToVideo render_SPA2_0deg.png video/render_SPA2_0deg.avi & 
./pictureToVideo render_SPA3_0deg.png video/render_SPA3_0deg.avi & 
./pictureToVideo render_SPA4_0deg.png video/render_SPA4_0deg.avi & 
./pictureToVideo render_SPA5_0deg.png video/render_SPA5_0deg.avi & 
./pictureToVideo render_SPA6_0deg.png video/render_SPA6_0deg.avi &
./pictureToVideo render_SPA7_0deg.png video/render_SPA7_0deg.avi & 
./pictureToVideo render_SPA8_0deg.png video/render_SPA8_0deg.avi

make clean
