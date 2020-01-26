#pragma once
#include <iostream>
#include <vector>

enum class DataType { Binary, TEXT };

class ErrorHandler
{
public:
	static void terminator();
	static void handle(const std::exception& e);
};

class Converter
{
public:
	auto fileExists(const std::string& Filename) -> bool;
	void convertFile(const std::string& Filename);

	// Converter();
};

class BinaryFile
{
public:
	std::string fileName;
	std::string encodedData;
	std::string defaultIdentifier;
	DataType contentType = DataType::Binary;
	long fileSize = 0;
	void readFromBinary();
	void readFromEncoded();
	void dumpToBinary() const;
	void dumpToBinary(const std::string& Path) const;
	void dumpToEncodedStr() const;
	void dumpToEncodedStr(const std::string& Path,
	                      const std::string& Identifier) const;
	void dumpToRawEncodedStr(const std::string& Path) const;
	void dumpToRawEncodedStr() const;
	auto getFileSize() const -> long;
	auto splitData() const -> std::vector<std::string>;

	BinaryFile() = default;
	explicit BinaryFile(const std::string& FileName,
	                    DataType ContentType = DataType::Binary);
};

class Util
{
public:
	static auto split(std::string Str, std::string Delims)
	-> std::vector<std::string>;
};

class Encoder
{
public:
	// pure virtual function providing interface framework.
	virtual auto encode(const char* Data) -> std::string = 0;
	virtual auto decode(const std::string& Data) -> char* = 0;
};

class Base64RawEncoder : public Encoder
{
public:
	auto encode(const char* Data) -> std::string override;
	auto decode(const std::string& Data) -> char* override;
};
