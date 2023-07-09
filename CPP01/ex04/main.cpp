#include <iostream>
#include <fstream>

int    main(int ac, char **av) {

    if (ac == 4)
    {
        if (!*av[1] || !*av[2] || !*av[3])
		{
			std::cerr << "argument is empty" << std::endl;
			return (2);
		}
        std::string     file_path = av[1];
		std::string     s1 = av[2];
		std::string     s2 = av[3];
        
        std::ifstream   ifs;
        ifs.open(file_path);
		if (!ifs.is_open())
		{
			std::cerr << "Can't open " << av[1] << std::endl;
			return (3);
		}
        
        std::ofstream   ofs;
        std::string     replace_file;
        std::string     line;
        
        replace_file = file_path.substr(0) + ".replace";
        ofs.open(replace_file);
        if (!ofs.is_open())
        {
			std::cerr << "Can't create " << replace_file << std::endl;
			return (4);
		}
        while (std::getline(ifs, line))
        {
            int pos = 0;

            while (1)
            {
                pos = line.find(s1, pos);
                if (pos == -1)
                    break ;
                line.erase(pos, s1.length());
                line.insert(pos, s2);
                pos += s2.length();
            }
            ofs << line << std::endl;
        }
        ofs.close();
    }
    else
    {
        std::cerr << "The program needs 3 arguments" << std::endl;
        return (1);
    }
}