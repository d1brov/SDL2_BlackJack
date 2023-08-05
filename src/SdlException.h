#pragma once

#include <exception>
#include <string>

class SdlException : public std::exception {
public:
	SdlException();
	explicit SdlException(const std::string& message);
	const char* what() const noexcept override;

private:
	std::string message_;
};