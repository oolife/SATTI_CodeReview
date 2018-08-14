// Copyright 2018 <Author>

#include "typing_machine.h"

TypingMachine::TypingMachine() {
	m_pCursor = new Node(0);
	m_pHeadOfList = m_pCursor;
	m_pTailOfList = m_pCursor;
	m_NumOfChar = 0;
	return;
}

void TypingMachine::HomeKey() {	
	m_pCursor = m_pHeadOfList;
    return;
}

void TypingMachine::EndKey() {

	m_pCursor = m_pTailOfList;
	return;
}

void TypingMachine::LeftKey() {

	if (m_pCursor == m_pHeadOfList)
	{
		return;
	}
	else
	{
		m_pCursor = m_pCursor->GetPreviousNode();
	}
	return;
}

void TypingMachine::RightKey() {
	
	if (m_pCursor == m_pTailOfList)
	{
		return;
	}
	else
	{
		m_pCursor = m_pCursor->GetNextNode();
	}
	return;
}

bool TypingMachine::TypeKey(char key) {
	
	if (key >= 0x20 && key <= 0x7E && m_NumOfChar < 100)
	{
		Node* pNewNode = m_pCursor->InsertPreviousNode(key);
		if (pNewNode == nullptr)
		{
			return false;
		}
		
		if (m_pCursor == m_pHeadOfList)
		{
			m_pHeadOfList = pNewNode;
		}
		m_NumOfChar++;
		return true;
	
	}
	return false;
}

bool TypingMachine::EraseKey() {
	
	bool result;

	if (m_pCursor == m_pHeadOfList)
	{
		return false;
	}
	else if (m_pCursor->GetPreviousNode() == m_pHeadOfList)
	{
		m_pHeadOfList = m_pCursor;
	}
	result = m_pCursor->ErasePreviousNode();

	if (result) 
	{
		m_NumOfChar--;
	}

	return result;
}

std::string TypingMachine::Print(char separator) {
	std::string retValue = "";
	Node* pNode = m_pHeadOfList;

	while (pNode != nullptr)
	{
		if (pNode == m_pCursor && separator != 0)
		{
			retValue += separator;
		}
		if (pNode == m_pTailOfList)
		{
			break;
		}

		retValue += pNode->GetData();
		pNode = pNode->GetNextNode();
	}
	return retValue;
}