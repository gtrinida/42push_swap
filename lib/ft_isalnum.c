int	ft_isalnum(int character)
{
	return ((character >= 48 && character <= 57)
		|| (character >= 65 && character <= 90)
		|| (character >= 97 && character <= 122));
}
