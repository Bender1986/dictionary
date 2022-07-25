#ifndef DIC_H
#define DIC_H

#include <iostream>
#include <map>


/* Interface NotFoundException */
template<class Key>
class NotFoundException : public std::exception
{
    public:
    
    virtual const Key& get_key() const noexcept = 0;
};


/* Class MapNotFoundException */
template<class Key>
class MapNotFoundException: public NotFoundException<Key>
{
    private:
    
    const Key m_key;

    public:

    MapNotFoundException(const Key& key) noexcept: m_key{key}{}

    const Key& get_key() const noexcept override
    {
        return m_key;
    }

    const char* what() const noexcept override 
    { 
        return "key not found";
    }  

};




/* Interface Dictionary */
template<class Key, class Value>
class Dictionary
{
    
    public:

    virtual ~Dictionary() = default;

    virtual const Value& get(const Key& key) const = 0;

    virtual void set(const Key& key, const Value& value) = 0;

    virtual bool is_set(const Key& key) const = 0;
};


/* Class MapDictionary */
template<class Key, class Value>
class MapDictionary: public Dictionary<Key, Value>
{
    
    private:

    std::map<Key, Value> m_dictionary;
    
    public:

    MapDictionary() noexcept = default;

    /* Lock default constuctor move, copy and operator = */
    MapDictionary(MapDictionary&&) noexcept = delete;
    
    /* Get Value */
    const Value& get(const Key& key) const override
    {
        auto it = m_dictionary.find(key);

        if (it == m_dictionary.end())
        {
            throw MapNotFoundException(key);
        }     

        return it->second;
    }  

    /* Set Value */
    void set(const Key& key, const Value& value) override
    {
        m_dictionary.emplace(key, value);
    }
    
    /* is check key in dictionary  */
    bool is_set(const Key& key) const override
    {
        auto it = m_dictionary.find(key);

        if (it != m_dictionary.end())
        {
            return true;
        }
        else return false;
    }

    /* Destructor */
    ~MapDictionary() override
    {
        std::cout << "Object from class MapDictionary is distroy \n";
    }   

};



#endif