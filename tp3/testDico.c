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

MU_TEST(test_dicofr) {
  NTree* tree;
  char string[20];

  tree = load("dico.fr");
  mu_assert_int_eq(1, search(tree, "ceci"));
  mu_assert_int_eq(1, search(tree, "bonjour"));
  mu_assert_int_eq(1, search(tree, "raclette"));
  mu_assert_int_eq(1, search(tree, "maison"));
  mu_assert_int_eq(1, search(tree, "manger"));
  mu_assert_int_eq(1, search(tree, "pi"));
}

MU_TEST_SUITE(test_suite) {
  MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

  MU_RUN_TEST(test_minidico);
  MU_RUN_TEST(test_dicofr);
}

int main(void) {

  MU_RUN_SUITE(test_suite);
  MU_REPORT();

  return 0;
}
