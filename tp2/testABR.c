#include <stdio.h>
#include "abr.h"
#include "minunit.h"

static NOEUD* abr;

void test_setup(void) {

}

void test_teardown(void) {

}

MU_TEST(test_nbFeuilles) {
  abr = insere(abr, 50);
  mu_assert_int_eq(1, nbFeuilles(abr));
  insere(abr, 25);
  insere(abr, 65);
  mu_assert_int_eq(2, nbFeuilles(abr));
  insere(abr, 12);
  insere(abr, 34);
  printf("\n");
  affiche_arbre(abr, 2, '>');
  mu_assert_int_eq(3, nbFeuilles(abr));
  destroyABR(abr);
  abr = NULL;
}

MU_TEST(test_noeudsLargeur) {
  abr = insere(abr, 50);
  mu_assert_int_eq(1, nbNoeudLargeur(abr));
  insere(abr, 25);
  insere(abr, 65);
  mu_assert_int_eq(3, nbNoeudLargeur(abr));
  insere(abr, 12);
  insere(abr, 34);

  mu_assert_int_eq(5, nbNoeudLargeur(abr));
  destroyABR(abr);
  abr = NULL;
}

MU_TEST_SUITE(test_suite) {
  MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

  MU_RUN_TEST(test_nbFeuilles);
  MU_RUN_TEST(test_noeudsLargeur);
}

int main(void) {

  MU_RUN_SUITE(test_suite);
  MU_REPORT();

  return 0;
}
