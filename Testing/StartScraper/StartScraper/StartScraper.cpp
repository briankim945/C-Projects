// StartScraper.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <libxml/tree.h>
#include <libxml/HTMLparser.h>
#include <libxml++/libxml++.h>
#include <libxml++/document.h>

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <curl/easy.h>

#define HEADER_ACCEPT "Accept:text/html,application/xhtml+xml,application/xml"
#define HEADER_USER_AGENT "User-Agent:Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.17 (KHTML, like Gecko) Chrome/24.0.1312.70 Safari/537.17"


// This is the function we pass to LC, which writes the output to a BufferStruct
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}

static void
print_element_names(xmlNode* a_node)
{
	xmlNode* cur_node = NULL;

	for (cur_node = a_node; cur_node; cur_node = cur_node->next) {
		if (cur_node->type == XML_ELEMENT_NODE) {
			printf("node type: Element, name: %s\n", cur_node->name);
			printf("node content: %s\n", cur_node->content);
		}

		print_element_names(cur_node->children);
	}
}

void parseHtml(xmlNode* cur)
{
	xmlChar* key;
	cur = cur->xmlChildrenNode;
	while (cur != NULL) {
		key = xmlNodeGetContent(cur);
		printf("keyword: %s\n", key);
		printf("name: %s\n", (char*)cur->name);
		printf("name: %s\n", (char*)cur->type);
		std::cout << (bool) xmlStrEqual(cur->name, (const xmlChar*)"a") << std::endl;
		xmlFree(key);
		cur = cur->next;
	}
	return;
}

void parseLinks(xmlNode* cur)
{
	xmlChar* key;
	xmlChar* link;
	cur = cur->xmlChildrenNode;
	while (cur != NULL) {
		if (1 == xmlStrEqual(cur->name, (const xmlChar*) "a"))
		{
			key = xmlNodeGetContent(cur);
			link = xmlGetProp(cur, (const xmlChar*) "href");
			printf("name: %s\n", (char *) cur->name);
			printf("URL: %s\n", (char *) link);
			xmlFree(key);
			cur = cur->next;
		}
	}
	return;
}

int main()
{

	curl_global_init(CURL_GLOBAL_ALL);
	CURL* myHandle;
	CURLcode result; // We’ll store the result of CURL’s webpage retrieval, for simple error checking.
	myHandle = curl_easy_init();

	std::string readBuffer;

	/* Notice the lack of major error checking, for brevity */

	curl_easy_setopt(myHandle, CURLOPT_WRITEFUNCTION, WriteCallback); // Passing the function pointer to LC
	curl_easy_setopt(myHandle, CURLOPT_WRITEDATA, &readBuffer); // Passing our BufferStruct to LC
	curl_easy_setopt(myHandle, CURLOPT_URL, "https://www.hackthissite.org/articles/read/1078");
	result = curl_easy_perform(myHandle);
	curl_easy_cleanup(myHandle);

	// Writing to file here
	std::ofstream out("test1.html");
	out << readBuffer;
	out.close();


	//PARSING

	// Parse HTML and create a DOM tree
	xmlDoc* doc = htmlReadDoc((xmlChar*)readBuffer.c_str(), NULL, NULL, HTML_PARSE_RECOVER | HTML_PARSE_NOERROR | HTML_PARSE_NOWARNING);

	/*
	// Encapsulate raw libxml document in a libxml++ wrapper
	xmlNode* r = xmlDocGetRootElement(doc);
	xmlpp::Element* root = new xmlpp::Element(r);

	// Grab the IP address
	std::string xpath = "//*[@id=\"locator\"]/p[1]/b/font/text()";
	auto elements = root->find(xpath);
	std::cout << "Your IP address is:" << std::endl;
	std::cout << dynamic_cast<xmlpp::ContentNode*>(elements[0])->get_content() << std::endl;

	*/

	xmlNode* root_element = NULL;
	/*Get the root element node */
	root_element = xmlDocGetRootElement(doc);

	//print_element_names(root_element);

	std::cout << "NEW" << std::endl;

	parseHtml(root_element);
	//parseLinks(root_element);

	//delete root;
	xmlFreeDoc(doc);

	xmlCleanupParser();

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
