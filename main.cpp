#include<iostream>
//#define ENABLE_DEBUG

void GetTime(int nProject)
{
	const int HOUR{ 60 };
	int nHours{ 0 };
	int nMinutes{ 0 };

	std::cout << "==================================================" << std::endl;
	std::cout << "Enter HOURS and MINUTES separated by a BLANKSPACE: ";
	std::cin >> nHours >> nMinutes;
#ifdef ENABLE_DEBUG
	//std::cerr << "nHours: " << nHours << std::endl;
	//std::cerr << "nMinutes: " << nMinutes << std::endl;
#endif

	int nConvertToMinutes{ nMinutes + (nHours * HOUR) };
	int nSplitMinutes{ nConvertToMinutes / nProject };
#ifdef ENABLE_DEBUG
	//std::cerr << "nConvertToMinutes: " << nConvertToMinutes << std::endl;
	//std::cerr << "nSplitMinutes: " << nSplitMinutes << std::endl;
#endif

	int nFinalHours{ nSplitMinutes / HOUR };
	int nFinalMinutes{ nSplitMinutes - (nFinalHours * HOUR) };
#ifdef ENABLE_DEBUG
	//std::cerr << "nFinalHours: " << nFinalHours << std::endl;
	//std::cerr << "nFinalMinutes: " << nFinalMinutes << std::endl;
#endif

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
#ifdef ENABLE_DEBUG
		//std::cerr << "Modulo result: " << nConvertToMinutes % nProject << "\n";
#endif
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