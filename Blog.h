#pragma once
class Blog
{
public:
	/// <summary>
	///  Properties
	/// </summary>

	char name[100];
	char text[1000];
	int lineCount;

	/// <summary>
	/// Methods
	/// </summary>
	Blog(char name[100], int blogSize);
	void Print();
	void AddLine(char* line);
	void loadFromFile();
	void saveInFile();
};


