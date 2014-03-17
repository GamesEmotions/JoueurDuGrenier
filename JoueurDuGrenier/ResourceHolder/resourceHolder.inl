
template <typename Resource, typename Identifier>
ResourceHolder<Resource,Identifier>* ResourceHolder<Resource,Identifier>::_singleton = nullptr;

template <typename Resource, typename Identifier>
ResourceHolder<Resource,Identifier>::ResourceHolder<Resource,Identifier>()
{
	this->loadEntity(Entities::Player, "resources/images/entities/player.png");
}

template <typename Resource, typename Identifier>
ResourceHolder<Resource,Identifier>::~ResourceHolder<Resource,Identifier>()
{
}

template <typename Resource, typename Identifier>
ResourceHolder<Resource,Identifier>* ResourceHolder<Resource,Identifier>::getInstance()
{
	if (ResourceHolder<Resource,Identifier>::_singleton == nullptr)
	{
		ResourceHolder<Resource,Identifier>::_singleton = new ResourceHolder<Resource,Identifier>();
	}
	return ResourceHolder<Resource,Identifier>::_singleton;
}

template <typename Resource, typename Identifier>
void ResourceHolder<Resource,Identifier>::load(Identifier id, const std::string& filename)
{
	std::unique_ptr<Resource> resource(new Resource());
	if (!resource->loadFromFile(filename))
	{
		throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);
	}

	auto inserted = _ResourcesHolder.insert(std::make_pair(id, std::move(resource)));
	assert(inserted.second);
}

template <typename Resource, typename Identifier>
template <typename Parameter>
void ResourceHolder<Resource,Identifier>::load(Identifier id, const std::string& filename, const Parameter& secondParameter)
{
	std::unique_ptr<Resource> resource(new Resource());
	if (!resource->loadFromFile(filename, secondParameter))
	{
		throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);
	}

	auto inserted = _ResourcesHolder.insert(std::make_pair(id, std::move(resource)));
	assert(inserted.second);
}

template <typename Resource, typename Identifier>
Resource& ResourceHolder<Resource,Identifier>::get(Identifier id)
{
	auto found = _ResourcesHolder.find(id);
	assert(found != _ResourcesHolder.end());

	return *found->second;
}

template <typename Resource, typename Identifier>
const Resource& ResourceHolder<Resource,Identifier>::get(Identifier id) const
{
	auto found = _ResourcesHolder.find(id);
	assert(found != _ResourcesHolder.end());

	return *found->second;
}