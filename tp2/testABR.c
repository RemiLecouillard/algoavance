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

MU_TEST(test_display) {
  NOEUD* abr;
  int i;
  int result;

  abr=NULL;
  abr = insere(abr, 1 );
  for ( i=2; i<=10; i++) {
    insere(abr, (i*5)%7 );
  }
  result = display( abr);

  printf("\n");
  mu_assert_int_eq(7, result);
}

MU_TEST(test_deuxFiles) {
  int i;
  NOEUD* abr = NULL;
  NOEUD* res = NULL;
  fifo *prefix, *sufix;

  prefix = createFifo();
  sufix = createFifo();
  abr = insere(abr, 11);
  for (i = 0; i < 10; i ++) {
    insere(abr, i);
  }
  deuxFiles(abr, prefix, sufix);
  dequeue(prefix, &res);
  mu_assert_int_eq(11, res->valeur);
  dequeue(prefix, &res);
  mu_assert_int_eq(0, res->valeur);
  dequeue(prefix, &res);
  mu_assert_int_eq(1, res->valeur);
  dequeue(prefix, &res);
  mu_assert_int_eq(2, res->valeur);
  dequeue(prefix, &res);
  mu_assert_int_eq(3, res->valeur);
  dequeue(prefix, &res);
  mu_assert_int_eq(4, res->valeur);
  dequeue(prefix, &res);
  mu_assert_int_eq(5, res->valeur);
  dequeue(prefix, &res);
  mu_assert_int_eq(6, res->valeur);
  dequeue(prefix, &res);
  mu_assert_int_eq(7, res->valeur);
  dequeue(prefix, &res);
  mu_assert_int_eq(8, res->valeur);
  dequeue(prefix, &res);
  mu_assert_int_eq(9, res->valeur);

  dequeue(sufix, &res);
  mu_assert_int_eq(9, res->valeur);
  dequeue(sufix, &res);
  mu_assert_int_eq(8, res->valeur);
  dequeue(sufix, &res);
  mu_assert_int_eq(7, res->valeur);
  dequeue(sufix, &res);
  mu_assert_int_eq(6, res->valeur);
  dequeue(sufix, &res);
  mu_assert_int_eq(5, res->valeur);
  dequeue(sufix, &res);
  mu_assert_int_eq(4, res->valeur);
  dequeue(sufix, &res);
  mu_assert_int_eq(3, res->valeur);
  dequeue(sufix, &res);
  mu_assert_int_eq(2, res->valeur);
  dequeue(sufix, &res);
  mu_assert_int_eq(1, res->valeur);
  dequeue(sufix, &res);
  mu_assert_int_eq(0, res->valeur);
  dequeue(sufix, &res);
  mu_assert_int_eq(11, res->valeur);
}

MU_TEST_SUITE(test_suite) {
  MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

  MU_RUN_TEST(test_nbFeuilles);
  MU_RUN_TEST(test_noeudsLargeur);
  MU_RUN_TEST(test_display);
  MU_RUN_TEST(test_deuxFiles);
}

int main(void) {

  MU_RUN_SUITE(test_suite);
  MU_REPORT();

  return 0;
}
