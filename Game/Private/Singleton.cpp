template<class T>
class Singleton 
{
protected:
	Singleton() {}
	~Singleton() { delete mObject; }

	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton) = delete;
public:


	static T* getInstance() 
	{
		if (mObject == nullptr)
		{
			mObject = new T();
			return mObject;
		}
		else
			return mObject;
	}
	

private:
	static T* mObject;

};


