#pragma once
#include<iostream>
#include"tableauException.h"
namespace data_structure {

	template <typename T>
	class tableau
	{
		 T* m_tab;
		 size_t m_capacity;
		 size_t m_nombre_element_courant;


		 void redimmensionner(size_t newCapacity) {
			 m_capacity = newCapacity;
			 T* array = new T[m_capacity];
			 for (size_t i = 0; i < m_nombre_element_courant; i++)
				 array[i] = m_tab[i];
			 delete[] m_tab;
			 m_tab = array;
		 }
	public:

		tableau(size_t capacity = 4)
			:m_capacity(capacity),
			m_nombre_element_courant(0) 
		{

			m_tab = new T[m_capacity];
			std::cout << "constructor" << std::endl;

		}

		tableau(const tableau<T>& t) 
			:// m_tab(t.m_tab), faux, c'est un pointeur.
			m_capacity(t.m_nombre_element_courant),
			m_nombre_element_courant(t.m_nombre_element_courant) 
		{
			m_tab = new T[m_capacity];
			for (size_t i = 0; i < m_nombre_element_courant; i++)
				m_tab[i] = t.m_tab[i];

		}

		tableau<T>& operator=(const tableau<T>& t) {
			if (this != &t) {
				delete[] m_tab;
				m_capacity = t.m_capacity;
				m_nombre_element_courant = t.m_nombre_element_courant;
				m_tab = new T[m_capacity];
				for (size_t i = 0; i < m_nombre_element_courant; i++)
					m_tab[i] = t.m_tab[i];
			}
			return *this;
		}

		~tableau() {
			delete[] m_tab;
			std::cout << "destructor" << std::endl;
		}

		void ajouter(const T& element) {
			if (m_nombre_element_courant > m_capacity) {
				throw arrayExcpetion::tableauException("exception : nombre d'element ajouter est plus grand que la capacité du tableau.");
			}
			if (m_nombre_element_courant < m_capacity - 1) {
				m_tab[m_nombre_element_courant] = element;
				m_nombre_element_courant++;
				return;
			}
			redimmensionner(2 * m_capacity);
			m_tab[m_nombre_element_courant] = element;
			m_nombre_element_courant++;
		}

		void print() const {
			for (size_t i = 0; i < m_nombre_element_courant; i++)
				std::cout << m_tab[i] << ", ";
			std::cout << std::endl;
		}

		T& operator[](int index) {

			if (index > m_nombre_element_courant || index < 0) {
				throw arrayExcpetion::tableauException("exception : out of bounders index.");
			}

			for (size_t i = 0; i < m_nombre_element_courant; i++) {
				if (index == i) {
					return m_tab[i];
				}
			}
		}

		const T& operator[](int index) const {
			if (index > m_nombre_element_courant || index < 0) {
				throw arrayExcpetion::tableauException("exception : out of bounders index.");
			}

			for (size_t i = 0; i < m_nombre_element_courant; i++) {
				if (index == i) {
					return m_tab[i];
				}
			}
		}

		bool rechercher(const T& element) const {
			for (size_t i = 0; i < m_nombre_element_courant; i++) {
				if (m_tab[i] == element) return true;
			}
			return false;
		}

	};

}


