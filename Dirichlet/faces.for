      PROGRAM FACES
      COMMON /VGI7/ VGSCL,ICHS,MODE
      COMMON /FOU/ LABL,IPIC(2500)
      DIMENSION ZERO (9)
      DIMENSION P(5),P1(5)
      character *2 ITEX(3)
      DIMENSION SAVE(12)
      DIMENSION D(90)
      DIMENSION X(90), V(3), VV(3), SUM(3), AMAT(9), CELL(6), CARMAT(9)
     1 ,BMAT(9)
      DIMENSION PLANE(90)
      DATA IPLANE /0/
      DATA IOFF /0/
      DATA ZERO /9*0.0/
      DATA ISAVE /1/
      DATA P/0.0, 0.0, 1.5, 0.0, 0.0/
      DATA P1 /.2, .2, 1.3, .2, .2/
      DATA ITEX /'C*','B*','A*'/
      DATA RMAX /0.0/
       CALL DEFINE (IPIC,2500)
       CALL SHW(IPIC)
      READ (*,1000) CELL
 1000 FORMAT (6F10.4)
      CALL CART (CELL,CARMAT)
    1 CONTINUE
      IPLANE = IPLANE + 1
      CALL CPYVEC (ZERO,SUM)
      READ (*,100,END=8000) ISTOP, VV
  100 FORMAT (I5,F15.4,2F10.4)
      IF (ISTOP .EQ. 0) GO TO 6000
      ISTOP = 3*ISTOP - 2
      DO 145 IEND=1,ISTOP,3
      READ (*,1000) X(IEND), X(IEND+1), X(IEND+2)
  145 CONTINUE
      IEND = ISTOP+3
  160 IEND = IEND - 3
      DO 1800 I=1,IEND,3
      CALL VECMUL (X(I),CARMAT,V)
      CALL CPYVEC(V,X(I))
      CALL VECSUM (SUM,V,SUM)
 1800 CONTINUE
      E = (IEND+2) / 3
C----GET THE CENTER OF MASS IN SUM
      CALL CONMUL (SUM, 1.0/E, SUM)
      CALL CPYMAT (ZERO,AMAT)
      DO 1900 I=1,IEND,3
      CALL VECDIF (X(I),SUM,V)
      CALL INRTIA(V,1.0,AMAT)
 1900 CONTINUE
      F = EIGEN1 (AMAT,V,BMAT)
      DORG = DOT (V,SUM)
      IF (DORG .GT. 0.0) GO TO 4000
      DORG = -DORG
      CALL CONMUL (V,-1.0,V)
 4000 CONTINUE
      IF (DOT(VV,VV) .LE. 1.0E-5) GO TO 130
      IF (ISAVE .GT. 7) GO TO  130
      CALL CPYVEC (VV,SAVE(ISAVE+3))
      CALL CPYVEC (V,SAVE(ISAVE))
      ISAVE = ISAVE + 6
  130 CONTINUE
      DO 4500 II=1,IEND,3
      D(II) = DOT (V,X(II)) - DORG
 4500 CONTINUE
      WRITE (*,4600) IPLANE,DORG,V, (X(IJ),X(IJ+1),X(IJ+2),D(IJ),IJ=
     2 1,IEND,3)
 4600 FORMAT(//' PLANE NUMBER',I3,' DIST.FROM ORG.=',F11.4, 6X/
     2 ' DIRECTION COSINES =', 3F8.4/6X,
     3 'X       Y        Z      DIST.FROM PLN.'/
     4 30(3F9.3,F11.4/))
      IF (IPLANE .LE. 1) GO TO 5000
      WRITE (*,4550)
 4550 FORMAT ('   PLN  ANGLE OF NORMALS')
      IP = 4*IPLANE - 7
      J = 0
      DO 4800 II=1,IP,4
      J = J + 1
      D(J) = ANGLE(V,ZERO,PLANE(II))
 4800 CONTINUE
      IP = IPLANE - 1
      WRITE (*,4850) (II,D(II),II=1,IP)
 4850 FORMAT (1X,I4,F10.4)
 5000 CALL CPYVEC (V,PLANE(4*IPLANE-3))
      PLANE (IPLANE*4) = DORG
      GO TO 1
 6000 CONTINUE
      IPLANE = IPLANE - 1
      IF (IPLANE .LE. 3) GO TO 6099
      CALL SEEK (RMAX,IPLANE,PLANE)
 6099 READ (*,6100) CELL
 6100 FORMAT (6F9.4)
      CALL CART (CELL,CARMAT)
      CALL INVER(CARMAT,PLANE)
      CALL TRNSPZ(PLANE,CARMAT)
      IF (ISAVE .NE. 13) GO TO 6005
      DO 6003 I=4,10,6
      CALL VECMUL (SAVE(I),CARMAT,VV)
      CALL UNIT (VV,VV)
      CALL CPYVEC (VV,SAVE(I))
 6003 CONTINUE
      CALL PAIR (SAVE(4),SAVE(10),SAVE(1),SAVE(7),AMAT)
      CALL MATMUL (AMAT,CARMAT,BMAT)
      CALL CPYMAT (BMAT,CARMAT)
 6005 CONTINUE
C   DRAW AND LABEL THE RECIPROCAL AXES
      DO 6001 I=1,3
      CALL TPOSTN(0.0,0.0,0.0)
      CALL VECMUL (P(I),CARMAT,VV)
      CALL UNIT (VV,V)
      CALL TLINE (V(1),V(2),V(3))
      CALL VECMUL (P1(I),CARMAT,VV)
      CALL UNIT (VV,V)
      CALL CONMUL (V,.85,V)
      CALL TLINE (V(1),V(2),V(3))
      CALL TEXT (ITEX(I))
 6001 CONTINUE

C    CHANGE TO DOTTED LINES (MODE=3 FOR THE VECTOR GENERAL)
      MODE = 3
      WRITE (*,6010)
 6010 FORMAT (' PLN   H    K    L    D')
 6002 CONTINUE
      IPLANE = 0
      IP = -3
 6050 CONTINUE
      IP = IP + 4
      IPLANE = IPLANE + 1
      READ (*,6200,END=8000) V,PLANE(IP+3)
 6200 FORMAT (4F10.4)
      IF (DOT(V,V) .LT. 1.0E-5) GO TO 9000
      WRITE (*,6300) IPLANE,V,PLANE(IP+3)
 6300 FORMAT (1X,I3,3(2X,F3.0),F6.2)
      CALL VECMUL (V,CARMAT,PLANE(IP))
      CALL UNIT (PLANE(IP),PLANE(IP))
      CALL CPYVEC(PLANE(IP),V)
      IF (IPLANE .LE. 1) GO TO 6050
      WRITE (*,4550)
      IPP = 4*IPLANE - 7
      J = 0
      DO 6800 II=1,IPP,4
      J = J + 1
      D(J) = ANGLE(V,ZERO,PLANE(II))
 6800 CONTINUE
      IPP = IPLANE - 1
      WRITE (*,4850) (II,D(II),II=1,IPP)
      GO TO 6050
 8000 CONTINUE
      IPLANE = IPLANE - 1
      CALL SEEK(RMAX,IPLANE,PLANE)
C      CALL FIVFIV
 9000 CONTINUE
      END
      SUBROUTINE SEEK(RMAX,IPLANE,PLANE)
      DIMENSION ZERO(9)
      DIMENSION PLANE(90)
      DIMENSION V(3)
      DIMENSION X(90)
      DIMENSION SUM(3)
      DIMENSION IRING(40)
      DIMENSION IY(150), IZ(150)
      DIMENSION  IV(6)
      DIMENSION IB(50)
      DIMENSION IPLAN(150)
      DATA ZERO /9*0.0/
      NEULER = 0
      NV = 0
      WRITE (*,9100)
 9100 FORMAT (33H0CALCULATED VERTICES*************,/,
     1 29H0VERTEX NO.      COORDINATES ,18X,10HPLANE NO.S ,/)
      IP1 = 4*IPLANE-11
      IP2 = IP1 + 4
      IP3 = IP2 + 4
      CALL CPYVEC(ZERO,SUM)
      TEMP = 0.0
      DO 1000 I=4,IP3,4
 1000 TEMP = TEMP + PLANE(I)
      TEMP = 1.0E-5 * TEMP / FLOAT(IPLANE)
      DO 9300 I1=1,IP1,4
      II1 = I1 + 4
      DO 9300 I2=II1,IP2,4
      II2 = I2 + 4
      DO 9300 I3=II2,IP3,4
      CALL SOLVE (PLANE(I1),PLANE(I2),PLANE(I3),V)
      DO 9200 I=1,IP3,4
      DDD = DOT(V,PLANE(I))
      IF ((DDD-PLANE(I+3)) .GT. TEMP) GO TO 9300
 9200 CONTINUE
C----HERE IF IT-S A GOOD VERTEX
      NV = NV + 1
      IJ1 = I1/4 + 1
      IJ2 = I2/4 + 1
      IJ3 = I3/4 + 1
      CALL CPYVEC (V,X(3*NV-2))
      WRITE (*,9250) NV,V,IJ1,IJ2,IJ3
 9250 FORMAT (1X,I3,5X,3F10.3,5X,3I4)
      NNV = NV*3
      IPLAN(NNV-2) = IJ1
      IPLAN(NNV-1) = IJ2
      IPLAN(NNV  ) = IJ3
 9300 CONTINUE

C   GET THE LARGEST DIMENSION OF THE CRYSTAL IF SCALING HAS
C   NOT YET BEEN ESTABLISHED
      IF (RMAX .LE. 0.0) THEN
         NNV=3*NV-2
         DO 9310 I=1,NNV,3
            RMAX = MAX(RMAX,DOT(X(I),X(I)))
 9310    CONTINUE
      ENDIF
      R = 19.0 / SQRT(RMAX)

      IP2 = 3*NV - 2
      IP1 = IP2 - 3
      WRITE (*,9350)
 9350 FORMAT (13H0CONNECTIVITY ,/,5H EDGE,4X,
     1 23H VERTICES        PLANES )
      N = 0
      DO 9500 I1 = 1,IP1,3
      II1 = I1 +3
      DO 9500 I2=II1,IP2,3
      NP = 0
      DO 9400 I=1,3
      DO 9400 J=1,3
      IF (IPLAN(I1+I-1) .NE. IPLAN(I2+J-1)) GO TO 9400
      NP = NP + 1
      IV (NP) = IPLAN(I1+I-1)
 9400 CONTINUE
      IF (NP .LT. 2) GO TO 9500
      IV1 = I1 / 3 + 1
      IV2 = I2 / 3 + 1
      N = N + 1
      CALL TPOSTN(R*X(I1),R*X(I1+1),R*X(I1+2))
      CALL TLINE (R*X(I2),R*X(I2+1),R*X(I2+2))
C----STORE THE EDGE-S VERTICES AND PLANES
      NNP = 2 * N
      IY(NNP-1) = IV1
      IY(NNP  ) = IV2
      IZ(NNP-1) = IV(1)
      IZ(NNP  ) = IV(2)
      WRITE (*,9450) N,IV1,IV2,(IV(I),I=1,NP)
 9450 FORMAT (1X,I3,2X,2(2X,I3),2X,5(3X,I4))
 9500 CONTINUE
      DO 9515 I=1,IPLANE
      DO 9520 J=1,NNP
      IF (IZ(J) .EQ. I) GO TO 9515
 9520 CONTINUE
      NEULER = NEULER + 1
      WRITE (*,9510) I
 9510 FORMAT (' PLANE ',I2,' WAS NOT USED')
 9515 CONTINUE
      NEULER = NV - N + IPLANE - NEULER
      IF (NEULER .NE. 2) WRITE (*,9550)
 9550 FORMAT (59H EULER'S TEST FOR FINITE, SIMPLY-CONNECTED POLYHEDRA FA
     2ILS   )
      VOL = 0.0
      DO 9600 I=1,IPLANE
      DIST = DOT(X(1),PLANE(4*I-3)) - PLANE(4*I)
      DIST = ABS(DIST)
      IF (DIST .LT. 1.0E-4) GO TO 9600
      WRITE (*,*) ' CALL RING FOR PLANE ',I,' ',IPLANE
      CALL RING (I,IY,IZ,NNP,IRING,NRING)
      VOL = VOL + VOLUME(DIST,X,IRING,NRING)
 9600 CONTINUE
      WRITE (*,9650) VOL
 9650 FORMAT (' VOLUME=',F10.3,' CC')
      RETURN
      END

      C**********************************************************************C
      SUBROUTINE SOLVE (A,B,C,V)
      DIMENSION A(4),B(4),C(4),V(3),AMAT(9)
C----------------------------------------------------------------------C
      DO 1000 I=1,3
      CALL MAT (AMAT,A,B,C)
      DD = DET(AMAT)
      IF (ABS(DD) .LT. 1.E-4) GO TO 9000
      AMAT(I)  = A(4)
      AMAT(I+3) = B(4)
      AMAT(I+6) = C(4)
      V(I) = DET(AMAT)/DD
 1000 CONTINUE
      RETURN
 9000 DO 9100 I=1,3
      V(I) = 1000000.0
 9100 CONTINUE
      END


      SUBROUTINE FIVFIV
      COMMON /FOU/ LABL,IPIC(2500)
C     PROGRAM FIV
      COMMON /FIV/ NATOMS,LIMIT,DMAX,DMIN,PHI,THETA,YANG
      COMMON /BVGPRE/ LOAD1,IXR(3),IARI,INTOFF,INTSCL,ISKIP,ISLPIC,
     2 NAMBYT,ISLCOR,IDELS(3),IRM(9),IWINDO,IWINXL(3),IWINXH(3),IEND
      DIMENSION XMAT(9),YMAT(9),ZMAT(9)
      DIMENSION ITTMAT(9)
      EQUIVALENCE (ITTMAT,TTMAT)
      INTEGER VGI45
      COMMON /VGI5/ X(3),DIAL(10),Y(4)
      DIMENSION TMAT(9),TTMAT(9)
      DATA R,R1 /.004,.09/
      DATA XMAT /1.,0.,0.,0.,1.,0.,0.,0.,1./
      DATA YMAT /1.,0.,0.,0.,1.,0.,0.,0.,1./
      DATA ZMAT /1.,0.,0.,0.,1.,0.,0.,0.,1./
      DIAL1 = DIAL(1)
    1 CONTINUE
      DIAL1P = DIAL1
      DIAL1 = DIAL(1)
      IFLAG = 0
      IF (ABS(DIAL2-DIAL(2))- .05) 1000,1000,1100
 1100 DIAL2 = DIAL(2)
      XMAT(5) = DIAL2 * R1
      CALL CALC(XMAT(5),XMAT(9),XMAT(6),XMAT(8))
      IFLAG = 1
 1000 CONTINUE
      IF (ABS(DIAL3-DIAL(3))- .05) 2000,2000,2100
 2100 DIAL3 = DIAL(3)
      ZMAT(1) = DIAL3 * R1
      CALL CALC (ZMAT(1),ZMAT(5),ZMAT(2),ZMAT(4))
      IFLAG = 1
 2000 CONTINUE
      IF (IFLAG .NE. 0) CALL MATMUL (XMAT,ZMAT,TMAT)
      IF (IY)  4000,4000,4100
 4000 CONTINUE
      YCORR =  YANG - DIAL(1) * R1
      IY = 1
 4100 CONTINUE
      YANG = YCORR + DIAL(1) * R1
      GO TO 4500
 4400 CONTINUE
      IY = 0
      YCORR = (DIAL1 - DIAL1P) * R1
      YANG = YANG + DIAL(6) * R  + YCORR
      IF (YANG .GT. 62.832) YANG = YANG - 62.832
      IF (YANG .LT. -62.832) YANG = YANG + 62.832
 4500 CONTINUE
      YMAT(1) = YANG
      CALL CALC(YMAT(1),YMAT(9),YMAT(3),YMAT(7))
      CALL MATMUL (YMAT,TMAT,TTMAT)
      DO 5000 I=1,9
      ITTMAT(I) = VGI45(TTMAT(I)*20.0)
 5000 CONTINUE
      DO 5500 I=1,9
      IRM(I) = ITTMAT(I)
 5500 CONTINUE
      INTOFF = VGI45(DIAL(4))
      INTSCL = VGI45(DIAL(5)) + 1
      GO TO 1
      END

      SUBROUTINE CALC (X1,X2,X3,X4)
      X3 = SIN(X1)
      X4 = - X3
      X2 = COS(X1)
      X1 = X2
      RETURN
      END

      SUBROUTINE RING (IPLAN,IY,IZ,NEDGE,IRING,NRING)
      DIMENSION  IY(NEDGE),IZ(NEDGE),IRING(NEDGE)
      NRING = 0
      NE2 =  NEDGE
      do 8000 iouter=1,neDGE
      DO 8000 I=1,NE2
      I2 = I
      IF (MOD(I,2) .EQ. 0) I2 = I2 - 1
      IF (IZ(I) .NE. IPLAN) GO TO 8000
      IF (NRING .EQ. 0) GO TO 2000
      IF (IY(I2).EQ. IRING(NRING)) GO TO 3000
      IF (IY(I2+1) .EQ. IRING(NRING)) GO TO 4000
      GO TO 8000
 2000 NRING = 2
      IRING(1) = IY(I2)
      IRING(2) = IY(I2+1)
      GO TO 7000
 3000 IRING(NRING+1) = IY(I2+1)
      GO TO 5000
 4000 IRING(NRING+1) = IY(I2)
 5000 IF (IRING(NRING+1) .EQ. IRING(1)) GO TO 9000
      NRING = NRING + 1
 7000 IZ(I) = 0
 8000 CONTINUE
      WRITE (*,*) ' exited at bottom of 8000 loop in ring for plane',
     2 IPLAN
      NRING = 0
 9000 CONTINUE
      RETURN
      END

      FUNCTION VOLUME (DIST,X,IRING,NRING)
      DIMENSION V(12)
      DIMENSION X(90),IRING(NRING)
      AREA = 0.0
      IR1 = 3*IRING(1) - 2
      DO 1000 I=2,NRING-1
      IR2 = 3*IRING(I) - 2
      IR3 = 3*IRING(I+1) - 2
      CALL VECDIF (X(IR1),X(IR2),V(4))
      CALL VECDIF (X(IR3),X(IR2),V(7))
      CALL CROSS (V(4),V(7),V(1))
C    ADD THE AREA OF THE CURRENT TRIANGLE (1/2*BASE*HEIGHT)
      AREA = AREA + 0.5*AMAG(V(1))
 1000 CONTINUE
      VOLUME = AREA * DIST / 3.0
      RETURN
      END



      subroutine define (i,n)
      end
      subroutine shw(i)
      end
      subroutine tpostn (a,b,c)
      end
      subroutine tline(a,b,c)
      end
      subroutine dial(n)
      end
      INTEGER function vgi45(a)
      end
      subroutine text(C)
      CHARACTER C
      end