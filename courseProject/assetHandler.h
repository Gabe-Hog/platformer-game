#ifndef ASSETHANDLER_H
#define ASSETHANDLER_H
#include <map>
#include <memory>
#include <string>
#include <stdexcept>


using namespace std;

/// <summary>
/// Class object needs to have function loadFromFile().
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T> 
class assetHandler
{
private:
	map<string, shared_ptr<T>> assetContainer;



public:
	assetHandler() = default;
	~assetHandler() = default;
	void addAsset(const string key, const string& filePath);
	T getAsset(string key) const;




};



template<typename T>
void assetHandler<T>::addAsset(const string key, const string& filePath)
{
	
	shared_ptr<T> asset = make_shared<T>();

	if (!asset->loadFromFile(filePath))
	{
		throw runtime_error("Error::AssetHandler::Could Not Load Asset:: ");
	}
	
		
	this->assetContainer.insert({ key, asset });


}

template<typename T>
T assetHandler<T>::getAsset(string key) const
{
	
	if (!this->assetContainer.at(key))
	{
		throw out_of_range("Error::AssetHandler::Did Not Contain Asset");
	}
	
	
	return *(this->assetContainer.at(key));
}
#endif