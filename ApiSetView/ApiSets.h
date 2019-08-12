#pragma once

struct ApiSetEntry {
	CString Name;
	std::vector<CString> Values, Aliases;
	bool Sealed;
};

class ApiSets {
public:
	ApiSets();

	void SearchFiles();

	const std::vector<ApiSetEntry>& GetApiSets() const;
	bool IsFileExists(const wchar_t* name) const;

private:
	struct LessNoCase {
		bool operator()(const CString& s1, const CString& s2) const {
			return s1.CompareNoCase(s2) < 0;
		}
	};
	using FileSet = std::set<CString, LessNoCase>;

	void Build();
	void SearchDirectory(const CString& directory, const CString& pattren, FileSet& files);

private:
	std::vector<ApiSetEntry> _entries;
	FileSet _files;
};

