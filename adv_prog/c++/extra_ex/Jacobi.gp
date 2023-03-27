# Generates animation from .dat files
# if you name them STEPNUMBER.dat and put into gif_dir
# adjust the output step as needed 

set terminal gif animate delay 20
set output 'Jacobi.gif'


set size square
unset colorbox
set palette rgb 33,13,10
set yr [] reverse #otherwise it flips the image due to default axis orientation

set view map # for a heat map


path="./Jacobi_data/"
extension=".dat"
do for [i=0:100] {
   filename=50*i 
   plot path.filename.extension matrix with image title "file: ".filename
} 

reset 
set output
set terminal qt #just to return back to normal output terminal; MIGHT NOT BE QT ON YOUR SYSTEM 
