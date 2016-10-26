	// test the vector of blocks 

	sf::Texture texture;
	texture.loadFromFile("images/blocks.png");

	std::vector<Block> grid;
	grid.resize(9);
	sf::Vector2f f(0, 0);
	int k = 0;
	for(int i = 0; i < 8; i++ )
	{
		grid[i] = Block(texture, f, true, sf::IntRect(k, 0, 103, 104));
		k += 105;
		f.y += 105*0.5;
	}

	sf::RenderWindow window(sf::VideoMode(400, 600), "Minesweeper");

	while (window.isOpen())
	{
	   // Event processing
	   sf::Event event;
	   while (window.pollEvent(event))
	   {
	       // Request for closing the window
	       if (event.type == sf::Event::Closed)
	           window.close();
	   }

	   	window.clear(sf::Color(0, 0, 0, 255));
	   	for(int i = 0; i < 9; i++ )
		{
			window.draw(grid[i].sprite);
		}

		window.display();
	}

	window.close();