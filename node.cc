// Copyright 2018 <Author>

#include "node.h"

Node::Node(char data) {
	m_chData = data;
	m_pPrevNode = nullptr;
	m_pNextNode = nullptr;
  return;
}

char Node::GetData() {
	return m_chData;
}

Node* Node::GetPreviousNode() {
	return m_pPrevNode;
}

Node* Node::GetNextNode() {
	return m_pNextNode;
}

Node* Node::InsertPreviousNode(char data) {
	
	Node* pNewNode = new Node(data);
	
	if (pNewNode != nullptr)
	{
		if (m_pPrevNode != nullptr)
		{
			m_pPrevNode->m_pNextNode = pNewNode;
			pNewNode->m_pPrevNode = m_pPrevNode;
		}
		m_pPrevNode = pNewNode;
		pNewNode->m_pNextNode = this;
	}
	return pNewNode;
}

Node* Node::InsertNextNode(char data) {
	
	Node* pNewNode = new Node(data);

	if (pNewNode != nullptr)
	{
		if (m_pNextNode != nullptr)
		{
			m_pNextNode->m_pPrevNode = pNewNode;
			pNewNode->m_pNextNode = m_pNextNode;
		}
		m_pNextNode = pNewNode;
		pNewNode->m_pPrevNode = this;
	}
	return pNewNode;
}

bool Node::ErasePreviousNode() {
	if (m_pPrevNode == nullptr)
	{
		return false;
	}
	else
	{
		Node* pNodeToErase = m_pPrevNode;
		m_pPrevNode = m_pPrevNode->m_pPrevNode;

		delete pNodeToErase;
		if (m_pPrevNode != nullptr)
		{ 
			m_pPrevNode->m_pNextNode = this;
		}
		return true;
	}
}

bool Node::EraseNextNode() {
	if (m_pNextNode == nullptr)
	{
		return false;
	}
	else
	{
		Node* pNodeToErase = m_pNextNode;
		m_pNextNode = m_pNextNode->m_pNextNode;

		delete pNodeToErase;
		if (m_pNextNode != nullptr)
		{
			m_pNextNode->m_pPrevNode = this;
		}
		return true;
	}
}
