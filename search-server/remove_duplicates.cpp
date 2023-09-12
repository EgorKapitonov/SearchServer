#include "remove_duplicates.h"
 
// 4: Функция поиска и удаления дубликатов:
void RemoveDuplicates(SearchServer& search_server) {
    
    std::set<int> id_remove;
    std::map<std::set<std::string>, int> document_remove;
    
    for (const int document_id : search_server) {
        
        std::set<std::string> save_words;
        std::map<std::string, double> all_words;
        
        all_words = search_server.GetWordFrequencies(document_id);
   
        for (auto [first, second] : all_words) {
            save_words.insert(first);
        }
        if (document_remove.count(save_words)) {
            id_remove.insert(document_id);
        } else {
            document_remove.insert(std::pair{save_words, document_id});
        }
    }
    for (auto i : id_remove) {
        std::cout<<"Found duplicate document id "<< i <<std::endl;
        search_server.RemoveDocument(i);
    }
}