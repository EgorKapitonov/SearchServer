#include <execution>
#include <algorithm>

#include "process_queries.h"

std::vector<std::vector<Document>> ProcessQueries(const SearchServer& search_server, 
                                                  const std::vector<std::string>& queries){
    
    std::vector<std::vector<Document>> queries_size(queries.size());
    
    std::transform(std::execution::par, queries.begin(), queries.end(), queries_size.begin(), [&search_server](std::string query) { return search_server.FindTopDocuments(query); });
    
    return queries_size;
}

std::vector<Document> ProcessQueriesJoined(const SearchServer& search_server, 
                                                   const std::vector<std::string>& queries){
    
    std::vector<Document> documents;
    
    for (auto document : ProcessQueries(search_server, queries)) {
        documents.insert(documents.end(), document.begin(), document.end());
    }
    
    return documents;
}