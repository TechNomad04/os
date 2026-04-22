    while(pages[tbr][1] != 0){
                    tbr = (tbr+1) %framesize;
                    if(tbr == start)
                    break;
                }

                for(i = 0; i < framesize; i++) 
                pages[i][1] = 0;

                pages[tbr][0] = page;
                pages[tbr][1] = 1;