rm -f his mine test.fillit
./generator -v -f $1
./fillit test.fillit > mine
./fillitTEST test.fillit > his
diff mine his
