This is a class project using root to analyze momentum data of three particles:


// Part 1.
    	// Calculate the total moment of each particle (H1,2,3: particle 1,2,3). PX, PY, PZ represent the momentum
    	// Print in the terminal, for each particle, the value of PX, PY, PZ and the total for the first 15 events
    	// Print these values ​​in a txt file, naming each column and the other chat task

// Part 2. 

	//NEW SCRIPT THAT CREATES A 3D HISTOGRAM BASED ON PX, PY, PZ WITH THE NEW TREE save in .ROOT make a loop and see what 	content each element has
	// Save and Plot the three momentum variables in a 3-dimensional histogram (ex. H1_PX. H1_PY, H1_PZ)

// Part 3. 
	Make a for loop and access the binContent of the 3D histogram and print it in the terminal
    	// Eg cout << "The content of the bin" << << "is" << endl;
    	// Useful command
    	// Int_t NbinsX = Histo-> GetNbinsX ();, same for Y, Z
    	// Int_t bin = Histo3D-> GetBin (i, j, k); i, j, k are dummy indices to loop the total bins.
    	// Double_t d1_val_data = Histo-> GetBinContent (bin);
    	// Double_t d1_val_MC = d1_hhh_MC-> GetBinError (bin);
    	// Plot the value obtained in each bin on a 1D histogram

    	// NEW SCRIPT THAT CREATES A 3D HISTOGRAM BASED ON PX, PY, PZ WITH THE NEW TREE

THE FILES:
*TotalMomentum.C calculates the total momentum, part 1.
*NewTREE.C generates a new data tree, part 1.
*NewHisto2D make a histogram in 2D, part 2.
*HistoBins.C y ExpF.C, part 3.  

pd: PhaseSpaceSimulation is the dataset that contains the raw data. its a tree that contains data of particle colitions
