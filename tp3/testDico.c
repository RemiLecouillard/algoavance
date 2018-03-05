#include <stdio.h>
#include "dico.h"
#include "minunit.h"

void test_setup(void) {

}

void test_teardown(void) {

}

MU_TEST(test_minidico) {
  NTree* tree;
  char string[20];

  tree = NULL;
  tree = add(tree, "ca");
  add(tree, "ce");
  add(tree, "ceci");
  add(tree, "cela");
  add(tree, "de");
  add(tree, "des");
  add(tree, "du");
  display(tree, string, 0);
  mu_assert_int_eq(1, search(tree, "ceci"));
  mu_assert_int_eq(1, search(tree, "ce"));
  mu_assert_int_eq(1, search(tree, "ca"));
  mu_assert_int_eq(1, search(tree, "cela"));
  mu_assert_int_eq(1, search(tree, "de"));
  mu_assert_int_eq(1, search(tree, "des"));
  mu_assert_int_eq(1, search(tree, "du"));
  mu_assert_int_eq(0, search(tree, "sdgsgsg"));

}

MU_TEST(test_dicoang) {
  NTree* tree;

  tree = load("dico.ang");
  mu_assert_int_eq(1, search(tree, "hello"));
  mu_assert_int_eq(1, search(tree, "daddy"));
  mu_assert_int_eq(1, search(tree, "house"));
  mu_assert_int_eq(1, search(tree, "eat"));
  mu_assert_int_eq(1, search(tree, "much"));

  mu_assert_int_eq(45370, nbWords(tree));
}

MU_TEST(test_dicofr) {
  NTree* tree;

  tree = load("dico.fr");
  mu_assert_int_eq(1, search(tree, "ceci"));
  mu_assert_int_eq(1, search(tree, "bonjour"));
  mu_assert_int_eq(1, search(tree, "raclette"));
  mu_assert_int_eq(1, search(tree, "maison"));
  mu_assert_int_eq(1, search(tree, "manger"));
  mu_assert_int_eq(1, search(tree, "pi"));

  mu_assert_int_eq(87051, nbWords(tree));
}

MU_TEST(test_save) {
  NTree* tree;
  NTree* tree2;

  tree2 = NULL;
  tree = NULL;
  tree = add(tree, "bonjour");
  add(tree,"bonsoir");
  add(tree, "salut");
  add(tree, "maison");
  add(tree, "mot");
  add(tree, "ordinateur");
  add(tree, "pastèque");
  add(tree, "glouton");
  save(tree, "dico.test");

  tree2 = load("dico.test");
  mu_assert_int_eq(1, search(tree2, "bonjour"));
  mu_assert_int_eq(1, search(tree2, "bonsoir"));
  mu_assert_int_eq(1, search(tree2, "salut"));
  mu_assert_int_eq(1, search(tree2, "maison"));
  mu_assert_int_eq(1, search(tree2, "mot"));
  mu_assert_int_eq(1, search(tree2, "ordinateur"));
  mu_assert_int_eq(1, search(tree2, "pastèque"));
  mu_assert_int_eq(1, search(tree2, "glouton"));

  mu_assert_int_eq(2, nbWordsBeginsBy(tree2, 'b'));
  mu_assert_int_eq(8, nbWords(tree2));
}

MU_TEST_SUITE(test_suite) {
  MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

  MU_RUN_TEST(test_minidico);
  MU_RUN_TEST(test_dicofr);
  MU_RUN_TEST(test_dicoang);
  MU_RUN_TEST(test_save);
}

int main(void) {

  MU_RUN_SUITE(test_suite);
  MU_REPORT();

  return 0;
}
