#include "stdafx.h"
#include "TeamStructure.h"

TeamStructure::TeamStructure()
{
}


TeamStructure::~TeamStructure()
{
}

HANDLE getHandle() {
	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);

	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	HANDLE hProcess = NULL;

	if (Process32First(snapshot, &entry) == TRUE)
	{
		while (Process32Next(snapshot, &entry) == TRUE)
		{
			if (wcscmp(entry.szExeFile, L"LeagueClient.exe") == 0)
			{
				hProcess = OpenProcess(PROCESS_VM_READ | PROCESS_QUERY_INFORMATION, FALSE, entry.th32ProcessID);
			}
		}
	}
	return hProcess;
}

template <class InIter1, class InIter2>
void find_all(unsigned char *base, InIter1 buf_start, InIter1 buf_end, InIter2 pat_start, InIter2 pat_end, DWORD *pAddress) {
	for (InIter1 pos = buf_start;
		buf_end != (pos = std::search(pos, buf_end, pat_start, pat_end));
		++pos)
	{
		*pAddress = (DWORD)(base + (pos - buf_start));
	}
}

void find_locs(HANDLE process, std::string const &pattern, DWORD *pAddress) {
	unsigned char *p = NULL;
	MEMORY_BASIC_INFORMATION info;

	for (p = NULL;
		VirtualQueryEx(process, p, &info, sizeof(info)) == sizeof(info);
		p += info.RegionSize)
	{
		std::vector<char> buffer;
		std::vector<char>::iterator pos;

		if (info.State == MEM_COMMIT &&
			(info.Type == MEM_MAPPED || info.Type == MEM_PRIVATE))
		{
			SIZE_T bytes_read;
			buffer.resize(info.RegionSize);
			ReadProcessMemory(process, p, &buffer[0], info.RegionSize, &bytes_read);
			buffer.resize(bytes_read);
			find_all(p, buffer.begin(), buffer.end(), pattern.begin(), pattern.end(), pAddress);
		}
	}
}

DWORD TeamStructure::getStructureString() {
	HANDLE hwnd = getHandle();
	std::string pattern = "\"myTeam\":[{\"assignedPosition\":\"";
	DWORD address;
	DWORD *pAddress = &address;
	int size = 3000;

	find_locs(hwnd, pattern, pAddress);
	std::cout << address << std::endl;

	return address;
}