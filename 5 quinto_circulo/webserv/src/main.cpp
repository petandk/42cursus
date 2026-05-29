/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmorello <pmorello@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 13:16:48 by pmorello          #+#    #+#             */
/*   Updated: 2026/05/26 20:26:06 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "web_server.hpp"   // Global project include 

#include <iostream>
#include <csignal>

// Global variable to control clean shutdown and avoid leaks under Valgrind
volatile bool g_running = true; 

void goodByeHandler(int sig)
{
    (void)sig;
    g_running = false;
}

int main(int argc, char *argv[])
{
    // Signals 
    signal(SIGINT, goodByeHandler);
    signal(SIGTERM, goodByeHandler);
    signal(SIGPIPE, SIG_IGN);

    if(argc > 2)
    {
        std::cout << "⚠️Wrong usage!⚠️" << std::endl;
        std::cout << "executable should be executed as follows:" << std::endl;
        std::cout << "./webserv [configuration file]" << std::endl;
        return (1);
    }

    ConfigParser configs;
    bool success = false;

    // Config parse
    if(argc == 2)
        success = configs.parseConfigFile(argv[1]);
    else
        success = configs.parseConfigFile();

    // Security check
    if (success && configs.getParsedServerConfigs().empty())
    {
        std::cerr << "\033[1;31m[ERROR] No server blocks found in config.\033[0m" << std::endl;
        success = false;
    }

    #ifdef DEBUG
        if (success) {
            printParsedConfig(configs);
        }
    #endif

    if (success)
    {   //before running, I check if all configured files and folders actually exists
        if (!runConfigPreflight(configs.getParsedServerConfigs()))
        {
            std::cerr << "[ERROR] Preflight failed. Check config paths/permissions." << std::endl;
            return (1);
        }
        Server webserv(configs);
        success = webserv.run();
        if (!g_running)
            std::cout << std::endl << "\033[1;32m[webserv] Server stopped. Goodbye!\033[0m" << std::endl;
    }

    /*
        !success because true = 1, false = 0
        but return expects 0 for no error, anything else for error
    */
    return (!success);
}
