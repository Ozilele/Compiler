// Division case 2:
// compiler->add_machine_command("PUT d"); // r_d <- r_a <- n
      // compiler->add_machine_command("SUB b"); // r_a <- r_a - r_b(n - p)
      // long long num1 = compiler->getCommandsNumber();
      // compiler->add_machine_command("JZERO ");
      // compiler->add_machine_command("GET d"); // r_a <- r_d <- n(reset dividend)
      // compiler->add_machine_command("RST f");
      // long long num2 = compiler->getCommandsNumber();
      // compiler->set_number(1, 4);
      // compiler->add_machine_command("SHL g"); // r_g <- 2 * r_g(2 * p)
      // compiler->add_machine_command("SUB g"); // r_a <- r_a - r_g(n - 2p)
      // compiler->add_machine_command("JZERO " + std::to_string(compiler->getCommandsNumber() + 4));
      // compiler->add_machine_command("GET d"); // r_a <- r_d(n)
      // compiler->add_machine_command("SHL e"); // r_e <- 2 * r_e
      // compiler->add_machine_command("JUMP " + std::to_string(compiler->getCommandsNumber() - 5));
      // compiler->add_machine_command("SHR g");
      // compiler->add_machine_command("GET d"); // r_a <- r_d <- n
      // compiler->add_machine_command("SUB g"); // r_a <- n - r_g
      // compiler->add_machine_command("INC a");
      // compiler->add_machine_command("SUB b"); // r_a <- r_a - r_b
      // compiler->add_machine_command("JZERO " + std::to_string(compiler->getCommandsNumber() + 11));
      // compiler->add_machine_command("ADD b");
      // compiler->add_machine_command("DEC a");
      // compiler->add_machine_command("PUT d");
      // compiler->add_machine_command("GET f");
      // compiler->add_machine_command("ADD e");
      // compiler->add_machine_command("PUT f");
      // compiler->add_machine_command("GET b");
      // compiler->add_machine_command("PUT g");
      // compiler->add_machine_command("GET d");
      // compiler->add_machine_command("JUMP " + std::to_string(num2));
      // compiler->add_machine_command("GET e");
      // compiler->add_machine_command("ADD f");
      // compiler->change_command(std::to_string(compiler->getCommandsNumber()), num1, 2);

      // Division case 1 case 5/n
      // compiler->add_machine_command("PUT g");
            // compiler->add_machine_command("PUT c");
            // compiler->set_number(result, 0);
            // compiler->add_machine_command("PUT e");
            // compiler->add_machine_command("SUB c");
            // long long num1 = compiler->getCommandsNumber();
            // compiler->add_machine_command("JZERO ");
            // compiler->add_machine_command("GET e");
            // compiler->add_machine_command("RST f");
            // long long num2 = compiler->getCommandsNumber();
            // compiler->set_number(1, 3);
            // compiler->add_machine_command("SHL g");
            // compiler->add_machine_command("SUB g");
            // compiler->add_machine_command("JZERO " + std::to_string(compiler->getCommandsNumber() + 4));
            // compiler->add_machine_command("GET e");
            // compiler->add_machine_command("SHL d");
            // compiler->add_machine_command("JUMP " + std::to_string(compiler->getCommandsNumber() - 5));
            // compiler->add_machine_command("SHR g");
            // compiler->add_machine_command("GET e");
            // compiler->add_machine_command("SUB g");
            // compiler->add_machine_command("INC a");
            // compiler->add_machine_command("SUB c");
            // compiler->add_machine_command("JZERO " + std::to_string(compiler->getCommandsNumber() + 11));
            // compiler->add_machine_command("ADD c");
            // compiler->add_machine_command("DEC a");
            // compiler->add_machine_command("PUT e");
            // compiler->add_machine_command("GET f");
            // compiler->add_machine_command("ADD d");
            // compiler->add_machine_command("PUT f");
            // compiler->add_machine_command("GET c");
            // compiler->add_machine_command("PUT g");
            // compiler->add_machine_command("GET e");
            // compiler->add_machine_command("JUMP " + std::to_string(num2));
            // compiler->add_machine_command("GET d");
            // compiler->add_machine_command("ADD f");
            // compiler->change_command(std::to_string(compiler->getCommandsNumber()), num1, 2);


            // Modulo case 1: 20 mod n
            // compiler->add_machine_command("GET ");
          // compiler->add_machine_command("DEC a");
          // long long num_ = compiler->getCommandsNumber();
          // compiler->add_machine_command("JZERO ");
          // compiler->add_machine_command("INC a");
          // compiler->add_machine_command("PUT c");
          // compiler->set_number(result, 0);
          // compiler->add_machine_command("INC a");
          // long long num2 = compiler->getCommandsNumber();
          // compiler->add_machine_command("PUT b");
          // compiler->add_machine_command("SUB c");
          // compiler->add_machine_command("JPOS " + std::to_string(num2));
          // compiler->add_machine_command("GET b");
          // compiler->add_machine_command("DEC a");
          // compiler->change_command(std::to_string(compiler->getCommandsNumber()), num_, 1);

             // for(int i = 1; i <= value; i++) {
        //   commandsToDo.push_back(std::string("INC a"));
        // }
        // for(int i = 1; i <= value; i++) {
        //   commandsToDo.push_back(std::string("INC ") + registerList[r]);
        // }
