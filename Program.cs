using System;
using System.Text;

namespace Myoga1012 {
	class Program {
		static void Main( string[] args ) {

			DateTime now = DateTime.Today;
			DateTime day = new DateTime( now.Year, now.Month, 1 );
			StringBuilder cal = new StringBuilder();
			for( int i = 0; i < ( int )day.DayOfWeek; cal.Append( "   " ), i++ );
			do {
				cal.AppendFormat( "{0, 3}", day.Day );
				if( day.DayOfWeek == DayOfWeek.Saturday ) cal.AppendLine();

			} while( ( day = day.AddDays( 1.0 ) ).Month == now.Month );
			Console.WriteLine( cal.ToString() );

		}
	}
}
