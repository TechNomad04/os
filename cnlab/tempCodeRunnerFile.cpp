    if (columns.size() >= 2) {
            string srcIP = columns[2];
            string destIP = columns[3];
            string info = columns[6];

            cout << left << setw(15) << srcIP 
                    << setw(15) << destIP 
                    << setw(10) << "See Info" 
                    << setw(10) << "See Info" 
                    << info << endl;
        }