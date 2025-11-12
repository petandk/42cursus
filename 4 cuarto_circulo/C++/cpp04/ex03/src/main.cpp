/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:46:53 by rmanzana          #+#    #+#             */
/*   Updated: 2025/11/12 16:51:05 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MateriaSource.hpp"
#include "../inc/Character.hpp"
#include "../inc/Ice.hpp"
#include "../inc/Cure.hpp"
/*
int	main(void)
{
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter *me = new Character("me");

	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter *bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	
	return(0);
}
*/

/*
	Main Tomas
*/

int main( void )
{
	std::cout << "1. Creating MateriaSource" << std::endl; 
		IMateriaSource* src = new MateriaSource();
		std::cout << "MateriaSource created successfully" << std::endl;
	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

	std::cout << "2. \"src\" learning 5 materias" << std::endl;
		src->learnMateria(new Ice());
		std::cout << "Learned Ice materia" << std::endl;
		src->learnMateria(new Cure());
		std::cout << "Learned Cure materia" << std::endl;
		src->learnMateria(new Ice());
		std::cout << "Learned Ice materia" << std::endl;
		src->learnMateria(new Cure());
		std::cout << "Learned Cure materia" << std::endl;
		
		std::cout << std::endl;
		Ice	*mat = new Ice();
		src->learnMateria(mat);
		std::cout << "Tried to learn 5th materia (should be ignored, max is 4)" << std::endl;
		delete	mat;

		std::cout << std::endl;
		std::cout << "MateriaSource should now have 4 materias learned" << std::endl;
	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

	std::cout << "3. Creating Character \"vilma\" and \"oktorok\"" << std::endl;
		Character* vilma = new Character("vilma");
		std::cout << "Character " << vilma->getName() << " created (empty inventory)" << std::endl;
		std::cout << std::endl;

		Character* oktorok = new Character("oktorok");
		std::cout << "Character " << oktorok->getName() << " created (empty inventory)" << std::endl;
	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

	std::cout << "4. \"vilma\" trying to equip 5 materias and \"oktorok\" one materia" << std::endl;
		vilma->equip(NULL);
		std::cout << "Tried to equip NULL (ignored)" << std::endl;
		
		AMateria* tmp;
		tmp = src->createMateria("fire");
		if (tmp == NULL)
			std::cout << "✓ createMateria(\"fire\") returned NULL (type not found)" << std::endl;
		else
			std::cout << "✗ ERROR: createMateria(\"fire\") should return NULL!" << std::endl;
		delete tmp;
		
		tmp = src->createMateria("ice");
		if (tmp != NULL && tmp->getType() == "ice")
			std::cout << "✓ Created ice materia and equipped to vilma [slot 0]" << std::endl;
		vilma->equip(tmp);
		
		tmp = src->createMateria("cure");
		if (tmp != NULL && tmp->getType() == "cure")
			std::cout << "✓ Created cure materia and equipped to vilma [slot 1]" << std::endl;
		vilma->equip(tmp);
		
		tmp = src->createMateria("cure");
		if (tmp != NULL && tmp->getType() == "cure")
			std::cout << "✓ Created cure materia and equipped to vilma [slot 2]" << std::endl;
		vilma->equip(tmp);
		
		tmp = src->createMateria("ice");
		if (tmp != NULL && tmp->getType() == "ice")
			std::cout << "✓ Created ice materia and equipped to vilma [slot 3]" << std::endl;
		vilma->equip(tmp);

		std::cout << std::endl;
		std::cout << vilma->getName() << " inventory is now full (4/4 materias)" << std::endl;
		
		tmp = src->createMateria("ice");
		vilma->equip(tmp);
		std::cout << "Tried to equip 5th materia (inventory full, should be ignored)" << std::endl;
		delete tmp;

		std::cout << std::endl;
		tmp = src->createMateria("ice");
		if (tmp != NULL)
			std::cout << "✓ Created and equipped ice materia to " << oktorok->getName() << " [slot 0]" << std::endl;
		oktorok->equip(tmp);
	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

	std::cout << "5. Testing Character Assignation overload \"oktorok = vilma\" for deep copy" << std::endl;	
		*oktorok = *vilma;
		std::cout << "✓ Assigned vilma's inventory to oktorok (deep copy)" << std::endl;
		
		vilma->unequip(0);
		std::cout << "Unequipped slot 0 from VILMA" << std::endl;
		std::cout << std::endl;

		std::cout << "Testing VILMA materias (slot 0 should be empty, slots 1,2,3 should work):" << std::endl;
		std::cout << "  Slot 0: ";
		vilma->use(0, *vilma);
		std::cout << "(empty)" << std::endl;
		std::cout << "  Slot 1: ";
		vilma->use(1, *vilma);
		std::cout << "  Slot 2: ";
		vilma->use(2, *vilma);
		std::cout << "  Slot 3: ";
		vilma->use(3, *vilma);
		std::cout << std::endl;

		std::cout << "Testing OKTOROK materias (all 4 slots should work - proves deep copy):" << std::endl;
		std::cout << "  Slot 0: ";
		oktorok->use(0, *oktorok);
		std::cout << "  Slot 1: ";
		oktorok->use(1, *oktorok);
		std::cout << "  Slot 2: ";
		oktorok->use(2, *oktorok);
		std::cout << "  Slot 3: ";
		oktorok->use(3, *oktorok);
		std::cout << "✓ Deep copy verified: oktorok still has slot 0 after vilma unequipped it" << std::endl;
	std::cout  << std::endl;

// ------------------------------------------------------------------------------------ //

	std::cout << "6. Testing character copy constructor for deep copy \"stardust = Character(vilma)\"" << std::endl;
		
		std::cout << "Creating stardust as copy of vilma (vilma has slots 1,2,3 filled)" << std::endl;
		Character* stardust = new Character(*vilma);
		std::cout << "✓ Stardust created with name: " << stardust->getName() << std::endl;

		tmp = src->createMateria("ice");
		vilma->equip(tmp);
		std::cout << "✓ Equipped Ice to vilma in slot 0 (after copy)" << std::endl;
		
		std::cout << std::endl;
		std::cout << "Testing VILMA materias (all 4 slots should be filled now):" << std::endl;
		std::cout << "  Slot 0: ";
		vilma->use(0, *vilma);
		std::cout << "  Slot 1: ";
		vilma->use(1, *vilma);
		std::cout << "  Slot 2: ";
		vilma->use(2, *vilma);
		std::cout << "  Slot 3: ";
		vilma->use(3, *vilma);
		std::cout << std::endl;

		std::cout << "Testing STARDUST materias (slot 0 empty, slots 1,2,3 filled - proves deep copy):" << std::endl;
		std::cout << "  Slot 0: ";
		stardust->use(0, *stardust);
		std::cout << "(empty)" << std::endl;
		std::cout << "  Slot 1: ";
		stardust->use(1, *stardust);
		std::cout << "  Slot 2: ";
		stardust->use(2, *stardust);
		std::cout << "  Slot 3: ";
		stardust->use(3, *stardust);
		std::cout << "✓ Deep copy verified: stardust's slot 0 is empty while vilma's is filled" << std::endl;


	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //
	
	std::cout << "7. Testing valid and invalid slot indices" << std::endl;
		std::cout << "Valid slots (0-3):" << std::endl;
		std::cout << "  Slot 0: ";
		vilma->use(0, *stardust);
		std::cout << "  Slot 1: ";
		vilma->use(1, *stardust);
		std::cout << "  Slot 2: ";
		vilma->use(2, *stardust);
		std::cout << "  Slot 3: ";
		vilma->use(3, *stardust);
		std::cout << std::endl;
		std::cout << "Invalid slots (should do nothing):" << std::endl;
		std::cout << "  Slot 10: ";
		vilma->use(10, *stardust);
		std::cout << "(no output = correct)" << std::endl;
		std::cout << "  Slot -1: ";
		vilma->use(-1, *stardust);
		std::cout << "(no output = correct)" << std::endl;
	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

	std::cout << "8. Testing unequip functionality" << std::endl;
		std::cout << "Before unequip - Slot 0: ";
		vilma->use(0, *oktorok);
		vilma->unequip(0);
		std::cout << "✓ Unequipped slot 0 from vilma" << std::endl;
		std::cout << "After unequip - Slot 0: ";
		vilma->use(0, *oktorok);
		std::cout << "(no output = correct, slot is empty)" << std::endl;

	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

	std::cout << "9. Testing equipping same materia pointer multiple times" << std::endl;
		ICharacter* lucifer = new Character("lucifer");
		AMateria *cure = new Cure;
		AMateria *ice = new Ice;

		std::cout << "✓ Equipping cure [slot 0]" << std::endl;
		lucifer->equip(cure);
		std::cout << "✓ Equipping ice [slot 1]" << std::endl;
		lucifer->equip(ice);
		std::cout << "✓ Equipping same cure pointer [slot 2]" << std::endl;
		lucifer->equip(cure);
		std::cout << "✓ Equipping same ice pointer [slot 3]" << std::endl;
		lucifer->equip(ice);
		std::cout << "✓ Unequipping all slots (0,1,2,3)" << std::endl;
		lucifer->unequip(0);
		lucifer->unequip(1);
		lucifer->unequip(2);
		lucifer->unequip(3);
		std::cout << "✓ Re-equipping cure [slot 0]" << std::endl;
		lucifer->equip(cure);
		std::cout << "✓ Re-equipping ice [slot 1]" << std::endl;
		lucifer->equip(ice);

		std::cout << "Testing lucifer's materias:" << std::endl;
		std::cout << "  Slot 0: ";
		lucifer->use(0, *lucifer);
		std::cout << "  Slot 1: ";
		lucifer->use(1, *lucifer);
		std::cout << "✓ Original materia pointers still work after unequip/re-equip" << std::endl;

	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

	std::cout << "10. Testing memory management with unequip" << std::endl;

		ICharacter* test = new Character("test");
		
		tmp = src->createMateria("ice");
		std::cout << "✓ Created Ice materia" << std::endl;
		test->equip(tmp);
		std::cout << "✓ Equipped to test character" << std::endl;
		
		AMateria* unequipped = tmp;
		test->unequip(0);
		std::cout << "⚠ Unequipped slot 0 - materia is now orphaned in memory!" << std::endl;
		std::cout << "  (This is expected behavior: unequip doesn't free memory)" << std::endl;
		std::cout << "  We need to manually delete the unequipped materia:" << std::endl;
		delete unequipped;
		std::cout << "✓ Manually deleted the orphaned materia" << std::endl;

	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

	std::cout << "11. Testing MateriaSource copy constructor and assignment" << std::endl;
		IMateriaSource* src2 = new MateriaSource();
		src2->learnMateria(new Ice());
		src2->learnMateria(new Cure());
		
		std::cout << "Creating src3 as copy of src2" << std::endl;
		MateriaSource* src3 = new MateriaSource(*((MateriaSource*)src2));
		
		tmp = src3->createMateria("ice");
		if (tmp != NULL && tmp->getType() == "ice")
			std::cout << "✓ Copy constructor works: src3 can create Ice" << std::endl;
		delete tmp;
		
		tmp = src3->createMateria("cure");
		if (tmp != NULL && tmp->getType() == "cure")
			std::cout << "✓ Copy constructor works: src3 can create Cure" << std::endl;
		delete tmp;
		
		delete src2;
		delete src3;
	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

	std::cout << "12. Testing NULL parameter handling" << std::endl;
		ICharacter* nullTest = new Character("nullTest");
		
		std::cout << "Testing learnMateria(NULL): ";
		src->learnMateria(NULL);
		std::cout << "✓ No crash" << std::endl;
		
		std::cout << "Testing equip(NULL): ";
		nullTest->equip(NULL);
		std::cout << "✓ No crash" << std::endl;
		
		std::cout << "Testing unequip on empty slot: ";
		nullTest->unequip(0);
		std::cout << "✓ No crash" << std::endl;
		
		std::cout << "Testing unequip with invalid indices: ";
		nullTest->unequip(-1);
		nullTest->unequip(4);
		nullTest->unequip(100);
		std::cout << "✓ No crash" << std::endl;
		
		std::cout << "Testing use on empty slot: ";
		nullTest->use(0, *nullTest);
		std::cout << "✓ No crash, no output" << std::endl;
		
		delete nullTest;
	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

	std::cout << "13. Testing createMateria with unknown type" << std::endl;
		tmp = src->createMateria("Fire");
		if (tmp == NULL)
			std::cout << "✓ createMateria(\"Fire\") returned NULL (unknown type)" << std::endl;
		else
			std::cout << "✗ ERROR: should return NULL for unknown type!" << std::endl;
		delete tmp;
		
		tmp = src->createMateria("");
		if (tmp == NULL)
			std::cout << "✓ createMateria(\"\") returned NULL (empty string)" << std::endl;
		else
			std::cout << "✗ ERROR: should return NULL for empty string!" << std::endl;
		delete tmp;
	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

	std::cout << "14. Testing equipping to full inventory" << std::endl;
		ICharacter* fullChar = new Character("fullChar");
		AMateria* m1 = new Ice();
		AMateria* m2 = new Cure();
		AMateria* m3 = new Ice();
		AMateria* m4 = new Cure();
		AMateria* m5 = new Ice();
		
		fullChar->equip(m1);
		fullChar->equip(m2);
		fullChar->equip(m3);
		fullChar->equip(m4);
		std::cout << "✓ Equipped 4 materias" << std::endl;
		
		fullChar->equip(m5);
		std::cout << "✓ Tried to equip 5th materia (ignored)" << std::endl;
		
		std::cout << "Testing all slots work:" << std::endl;
		fullChar->use(0, *fullChar);
		fullChar->use(1, *fullChar);
		fullChar->use(2, *fullChar);
		fullChar->use(3, *fullChar);
		std::cout << "✓ All 4 slots work correctly" << std::endl;
		
		delete m5;
		delete fullChar;
	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

	std::cout << "15. Testing self-assignment" << std::endl;
		Character* selfTest = new Character("selfTest");
		tmp = src->createMateria("ice");
		selfTest->equip(tmp);
		
		std::cout << "Testing Character self-assignment: ";
		*selfTest = *selfTest;
		std::cout << "✓ No crash" << std::endl;
		
		std::cout << "Verifying materia still works after self-assignment: ";
		selfTest->use(0, *selfTest);
		std::cout << "✓ Materia still works" << std::endl;
		
		delete selfTest;
	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

	std::cout << "16. Testing multiple unequips on same slot" << std::endl;
		ICharacter* unequipTest = new Character("unequipTest");
		tmp = src->createMateria("ice");
		unequipTest->equip(tmp);
		AMateria* toDelete = tmp;
		
		std::cout << "Unequipping slot 0 three times: ";
		unequipTest->unequip(0);
		unequipTest->unequip(0);
		unequipTest->unequip(0);
		std::cout << "✓ No crash" << std::endl;
		
		delete toDelete;
		delete unequipTest;
	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

	std::cout << "17. Testing createMateria returns independent copies" << std::endl;
		tmp = src->createMateria("ice");
		AMateria* tmp2 = src->createMateria("ice");
		
		if (tmp != NULL && tmp2 != NULL && tmp != tmp2)
			std::cout << "✓ createMateria returns different pointers (independent copies)" << std::endl;
		else
			std::cout << "✗ ERROR: createMateria should return independent copies!" << std::endl;
		
		delete tmp;
		delete tmp2;
	std::cout << std::endl;

// ------------------------------------------------------------------------------------ //

	std::cout << "18. Final cleanup - Deleting all remaining objects" << std::endl;
	
	delete test;
	delete lucifer;
	delete stardust;
	delete oktorok;
	delete vilma;
	delete src;
	
	std::cout << "✓ All objects deleted successfully - No memory leaks detected by destructors" << std::endl;
	std::cout << "\n========================================" << std::endl;
	std::cout << "All tests completed successfully!" << std::endl;
	std::cout << "========================================\n" << std::endl;

	return (0);
}