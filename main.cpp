#include<iostream>

void GetTime(int nProject)
{
	int nHours{ 0 };
	int nMinutes{ 0 };

	std::cout << "==================================================" << std::endl;
	std::cout << "Enter HOURS and MINUTES separated by a BLANKSPACE: ";
	std::cin >> nHours >> nMinutes;
	//std::cerr << "nHours: " << nHours << std::endl;
	//std::cerr << "nMinutes: " << nMinutes << std::endl;

	int nConvertToMinutes{ nMinutes + (nHours * 60) };
	//std::cerr << "nConvertToMinutes: " << nConvertToMinutes << std::endl;
	int nSplitMinutes{ nConvertToMinutes / nProject };
	//std::cerr << "nSplitMinutes: " << nSplitMinutes << std::endl;

	int nFinalHours{ nSplitMinutes / 60 };
	//std::cerr << "nFinalHours: " << nFinalHours << std::endl;
	int nFinalMinutes{ nSplitMinutes - (nFinalHours * 60) };
	//std::cerr << "nFinalMinutes: " << nFinalMinutes << std::endl;

	if (nFinalMinutes < 10)
	{
		std::cout << "Time per project = " << nFinalHours << ":0" << nFinalMinutes << "\n";
	}
	else
	{
		std::cout << "Time per project = " << nFinalHours << ":" << nFinalMinutes << "\n";
	}

	if (nConvertToMinutes % nProject > 0)
	{
		//std::cerr << "Modulo result: " << nConvertToMinutes % nProject << "\n";
		int nRemainingMinutes{ nConvertToMinutes - (nFinalMinutes * nProject) - (nFinalHours * nProject * 60) };
		std::cout << "Remaining minutes: " << nRemainingMinutes << "\n";
	}

}

int main()
{
	int nProject{ 0 };

	std::cout << "\t\t\t\t\t\t\tMade by Distantaziq" << std::endl;
	std::cout << "Enter amount of PROJECTS: ";
	std::cin >> nProject;

	do
	{
		GetTime(nProject);
	}

	while (nProject != 0);

	return 0;
}