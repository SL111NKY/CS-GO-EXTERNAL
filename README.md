# ZZZETA CS:GO PRIVATE

never detected cs:go private cheat for family and friends
outdated since cs2

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

## Additional Functions
```bash
utils: xor - imgui (removed)
```
```cpp


# MEMORY TEMPLATES
	template <class T>
	inline bool Read(std::uintptr_t dwAddress, T& Value)
	{
		return ReadProcessMemory();
	}

	template <class T>
	inline bool Write(std::uintptr_t dwAddress, const T& Value)
	{
		return WriteProcessMemory();
	}

	template <class T> 
	constexpr const T ReadN(const std::uintptr_t& dwAddress) const noexcept {
			T value = { };
			 ReadProcessMemory();
			 return value;
		}

	template <class T>
	constexpr void WriteN(const std::uintptr_t& dwAddress, const T& value) const noexcept {
		WriteProcessMemory();
	}
```

## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

[MIT](https://de.wikipedia.org/wiki/MIT-Lizenz)
