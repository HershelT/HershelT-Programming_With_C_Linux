mkdir cs3144
cp -r /share/ex_data/ex1/stuff cs3144
mv cs3144/stuff/lecture1_notes.txt cs3144
cd cs3144/stuff
chmod -R a+w ../*
rm file2{2,4}*
chmod 750 file01
echo "this is my line of text and I am proud of it" > ../my.newfile
cd ../../
mv cs3144/stuff/fill2 cs3144/stuff/file2.new