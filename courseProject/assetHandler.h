#ifndef ASSETHANDLER_H
#define ASSETHANDLER_H
#include <map>
#include <memory>
#include <string>
#include <stdexcept>


using namespace std;

template<typename T> 
class assetHandler
{
private:
	map<string, shared_ptr<T> assetContainer;



public:
	void addAsset(const string searchWord, const string& filePath);

	T getAsset(string key) const;




};

#endif

template<typename T>
void assetHandler<T>::addAsset(const string searchWord, const string& filePath)
{
	
	shared_ptr<asset> = make_shared<T>;
	if (!assset.loadFromFile(filePath) {
		throw "Error::AssetHandler::Could Not Load Asset:: ";
	}
	
		
	this->assetContainer.insert(searchWord, asset);


}

template<typename T>
T assetHandler<T>::getAsset(string key) const
{
	if (!this->assetHandler.contains(key))
	{
		throw "Error::AssetHandler::Did Not Contain Asset";
	}
	this->assetHandler.find(key);
	return T();
}
