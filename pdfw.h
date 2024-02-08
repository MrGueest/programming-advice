//stands for programming advice framework for useful functions to better and quicker programming
//Functions of Strings

string ReadString(string Msg)
{
	string Text;
	cout << Msg;
	getline(cin >> ws , Text);
	return Text;
}

char ReadChar()
{
	char X;
	cout << "\nPlease enter char :\n";
	cin >> X;
	return X;
}

char InvertingCharacter(char MyChar)
{
	return (isupper(MyChar)) ? tolower(MyChar) : toupper(MyChar);
}

void PrintFirstLettersOfString(string Text)
{
	bool IsSpace = true;
	for (int i = 0; i < Text.length(); i++)
	{
		if (Text[i] != ' ' && IsSpace)
			cout << Text[i] << endl;
		IsSpace = (Text[i] == ' ') ? true : false;
	}
}

string UpperFirstLetterOfEachWord(string Text)
{
	bool IsSpace = true;
	for (int i = 0; i < Text.length(); i++)
	{
		if (Text[i] != ' ' && IsSpace)
			Text[i] = toupper(Text[i]);
		IsSpace = (Text[i] == ' ') ? true : false;
	}
	return Text;
}

string LowerFirstLetterOfEachWord(string Text)
{
	bool IsSpace = true;
	for (int i = 0; i < Text.length(); i++)
	{
		if (Text[i] != ' ' && IsSpace)
			Text[i] = tolower(Text[i]);
		IsSpace = (Text[i] == ' ') ? true : false;
	}
	return Text;
}

string UpperAllLetterOfString(string Text)
{
	for (int i = 0; i < Text.length(); i++)
	{
		Text[i] = toupper(Text[i]);
	}
	return Text;
}

string LowerAllLetterOfString(string Text)
{
	for (int i = 0; i < Text.length(); i++)
	{
		Text[i] = tolower(Text[i]);
	}
	return Text;
}

string InvertAllLettersOfString(string Text)
{
	for (int i = 0; i < Text.length(); i++)
	{
		Text[i] = InvertingCharacter(Text[i]);
	}
	return Text;
}

short CountCapital_SmallLetters(string Text, enLetterType Enum = ::All)
{
	if (Enum == All)
		return Text.length();
	short Counter = 0;
	for (short i = 0; i < Text.length(); i++)
	{
		if (Enum == enLetterType::Capital)
		{
			if (isupper(Text[i]))
				Counter++;
		}
		if (Enum == enLetterType::Small)
		{
			if (islower(Text[i]))
				Counter++;
		}
	}
	return Counter;
}

short CountLettersByMatchCase(string Text, char CharToCount, bool MatchCase = true)
{
	short Counter = 0;
	for (int i = 0; i < Text.length(); i++)
	{
		if (MatchCase == false)
		{
			if (toupper(Text[i]) == toupper(CharToCount))
				Counter++;
		}
		else
			if (Text[i] == CharToCount)
				Counter++;
	}
	return Counter;
}

bool isvowel(char i)
{
	i = tolower(i);
	return (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') ? true : false;
}

short CountVowelLetters(string Text)
{
	short Counter = 0;
	for (int i = 0; i < Text.length(); i++)
	{
		if (isvowel(Text[i]))
			Counter++;
	}
	return Counter;
}

string PrintAllVowelsInString(string Text, string Space = "  ")
{
	string Vowels;
	for (int i = 0; i < Text.length(); i++)
	{
		if (isvowel(Text[i]))
			Vowels += Text[i] + Space;
	}
	return Vowels;
}

void  PrintEachWordInString(string Text)
{
	string Space = " ";
	string NewText;
	int Pos;
	while ((Pos = Text.find(Space)) != string::npos)
	{
		NewText = Text.substr(0, Pos);
		if (NewText != "")
			cout << NewText << endl;
		Text.erase(0, Pos + Space.length());
	}
	if (Text != "")
		cout << Text << endl;
}

short CountEachWordInString(string Text)
{
	short Counter = 0;
	string Space = " ";
	string NewText;
	int Pos;
	while ((Pos = Text.find(Space)) != string::npos)
	{
		NewText = Text.substr(0, Pos);
		if (NewText != "")
			Counter++;
		Text.erase(0, Pos + Space.length());
	}
	if (Text != "")
		return ++Counter;
}

vector <string> SplitString(string Text, string Space)
{
	vector <string> vSplit;
	string NewText;
	int Pos;
	while ((Pos = Text.find(Space)) != string::npos)
	{
		NewText = Text.substr(0, Pos);
		if (NewText != "")
		{
			vSplit.push_back(NewText);
		}
		Text.erase(0, Pos + Space.length());
	}
	if (Text != "")
		vSplit.push_back(Text);
	return vSplit;
}

string TrimLeft(string Text, char Delim)
{
	for (int i = 0; i < Text.length(); i++)
	{
		if (Text[i] != Delim)
			return Text = Text.substr(i, Text.length());
	}
}

string TrimRight(string Text, char Delim)
{
	for (int i = 0; i < Text.length(); i++)
	{
		if (Text[Text.length() - i - 1] != Delim)
			return Text = Text.substr(0, Text.length() - i);
	}
}

string Trim(string Text, char Delim)
{
	return TrimLeft(TrimRight(Text, Delim), Delim);
}

string JoinString(vector <string> vSplit, string Delim)
{
	string Line;
	for (string& temp : vSplit)
		Line += temp + Delim;
	return Trim(Line, '#');
}

string JoinString(string ArrString[], short length, string Delim)
{
	string Line;
	for (int i = 0; i < length; i++)
	{
		Line += ArrString[i] + Delim;
	}
	return Trim(Line, '*');
}

string ReverseWords(string Text)
{
	string Line;
	vector <string> vSplit = SplitString(Text, " ");
	vector <string>::iterator iter = vSplit.end();
	while (iter != vSplit.begin())
	{
		--iter;
		Line += *iter + " ";
	}
	Line = Line.substr(0, Line.length() - 1);
	return Line;
}

string ReplaceWords(string Text, string Word, string Replace)
{
	int Pos;
	while ((Pos = Text.find(Word)) != string::npos)
		Text = Text.replace(Pos, Word.length(), Replace);
	return Text;
}

string ReplaceWordsCustom(string Text, string Word, string Replace, bool MatchCase = true)
{
	int Pos;
	vector <string> vText = SplitString(Text, " ");
	if (MatchCase)
	{
		while ((Pos = Text.find(Word)) != string::npos)
		{
			Text = Text.replace(Pos, Word.length(), Replace);
			vText = SplitString(Text, " ");
		}
	}
	else
		for (string& temp : vText)
			if (LowerAllLetterOfString(Word) == LowerAllLetterOfString(temp))
				temp = Replace;
	return JoinString(vText, " ");
}

string RemovePuncuations(string Text)
{
	for (int i = 0; i < Text.length(); i++)
	{
		if (ispunct(Text[i]))
			Text[i] = ' ';
	}
	return Text;
}

string PrintStringWithoutPunct(string Text, string Space)
{
	string Word;
	vector <string> vText = SplitString(Text, " ");
	for (string& temp : vText)
		Word += temp + Space;
	return Word.substr(0, Word.length() - 1);
}





//Dahmane.
int cmp(int l, int r,bool rev=false)//return 1 if l(left) greater 0 if l equals r(right) -1 if r greater annd reverse evriting ig rev set to true 
{if (!rev) return int(l < r)-int(l > r);else return int(l > r)-int(l < r);}
template <typename T, size_t N> int cindx(int v,T (&arr)[N],bool offest=false) // works as floor but with arrays (by default) returns index of value that are less or equals the int if int are less then the first index will return -2 if you set offest to true will reverse evriting and return -1 if the value are greater then last index 
{for(int i=0;i<sizeof(arr)/N;i++){if (cmp(arr[i],v,true) == 1){if(!offest) return -2;else return 0;}if((cmp(arr[i],v) == 1 ||cmp(arr[i],v) == 0) && cmp(arr[i+1],v,true) == 1){return int(offest)+i;}}if(!offest)return sizeof(arr)/N;else return -1;}
