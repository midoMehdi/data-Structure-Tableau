#pragma once
#include<iostream>
#include<string>
#include<exception>
namespace arrayExcpetion {

	class tableauException
	{

		std::string m_message;

	public:
		tableauException(const std::string& message) : m_message(message) {

		}
		~tableauException() {

		}

		std::string print() const {
			return m_message;
		}

	};
}


