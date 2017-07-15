#ifndef RESOURCE_HPP_
# define RESOURCE_HPP_

namespace Resource
{
	namespace Texture
	{
		enum ID
		{
			None = -1,
			First = 0,
			Codec = First,
			Snake,
			Otacon,
			Campbell,
			Meryl,
			Naomi,
			Mei,
			Miller,
			Wolf,
			Jim,
			Size
		};
	}

	namespace Sound
	{
		enum ID
		{
			None = -1,
			First = 0,
			Size
		};
	}

	namespace Font
	{
		enum ID
		{
			None = -1,
			First = 0,
			Size
		};
	}
}

#endif // !RESOURCE_HPP_
