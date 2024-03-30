# ZZZETA CS:GO PRIVATE

never detected cs:go private cheat for family and friends

## Structure

+ Entity.h - Offsets
+ handle.h - handle to cs:go.exe
+ main.cpp - main running cls
+ memorymanage.cpp - copy pasted mem class
+ memorymanage.h - custom read- and write process memory struct
+ offsets.h - insert current offsets here
+ quickmaths - some maths for vectors and clamping/normalizing angles
+ xor.h - XOR String Avoid Detection by string patterns
## Features / Protections
+ cmd 
+ glows
+ trigger
+ aimer
+ rcs 
+ bhop
+ noflash
- radar
- etc..

## Additional Functions
```bash
utils: xor - imgui (removed)
```
```cpp


# returns 'true' or 'false'
	template <class T>
	inline bool Read(std::uintptr_t dwAddress, T& Value)
	{
		return ReadProcessMemory(m_hProcess, reinterpret_cast<LPVOID>(dwAddress), reinterpret_cast<LPVOID>(&Value), sizeof(T), NULL);
	}

	template <class T>
	inline bool Write(std::uintptr_t dwAddress, const T& Value)
	{
		return WriteProcessMemory(m_hProcess, reinterpret_cast<LPVOID>(dwAddress), reinterpret_cast<LPCVOID>(&Value), sizeof(T), NULL);
	}

	template <class T> 
	constexpr const T ReadN(const std::uintptr_t& dwAddress) const noexcept {
			T value = { };
			 ReadProcessMemory(m_hProcess, reinterpret_cast<const void*>(dwAddress), &value, sizeof(T), NULL);
			 return value;
		}

	template <class T>
	constexpr void WriteN(const std::uintptr_t& dwAddress, const T& value) const noexcept {
		WriteProcessMemory(m_hProcess, reinterpret_cast<void*>(dwAddress), &value, sizeof(T), NULL);
	}
```

## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

[MIT](https://de.wikipedia.org/wiki/MIT-Lizenz)
