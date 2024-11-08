#include <algorithm>
#include <vector>

/** STUDENT_TODO: You will need to include a relevant header file here! */

#include "autograder/utils.hpp"

/**
 * A course. This should be familiar from Assignment 1!
 */
struct Course
{
  std::string title;
  std::string number_of_units;
  std::string quarter;

  /**
   * You don't have to ignore this anymore! We're defining the `==` operator for
   * the Course struct.
   */
  bool operator==(const Course& other) const
  {
    return title == other.title && number_of_units == other.number_of_units &&
           quarter == other.quarter;
  }
};

class CourseDatabase
{
public:
  CourseDatabase(std::string filename)
  {
    auto lines = read_lines(filename);
    std::transform(lines.begin(),
                   lines.end(),
                   std::back_inserter(courses),
                   [](std::string line) {
                     auto parts = split(line, ',');
                     return Course{ parts[0], parts[1], parts[2] };
                   });
  }

  /**
   * Finds a course in the database with the given title, if it exists.
   * @param course_title The title of the course to find. 
   * @return You will need to figure this out!
   */
  FillMeIn find_course(std::string course_title)
  {
    /* STUDENT_TODO: Implement this method! You will need to change the return type. */
    throw std::runtime_error("find_course not implemented");
  }

private:
  std::vector<Course> courses;
};

int
main(int argc, char* argv[])
{
    static_assert(!std::is_same_v<std::result_of<decltype(&CourseDatabase::find_course)(CourseDatabase, std::string)>::type, FillMeIn>, "You must change the return type of CourseDatabase::find_course to something other than FillMeIn.");

  if (argc == 2) {
    CourseDatabase db("autograder/courses.csv");
    auto course = db.find_course(argv[1]);
    if (course) {
      std::cout << "Found course: " << course->title << "," << course->number_of_units << "," << course->quarter << "\n";
    } else {
      std::cout << "Course not found.\n";
    }
    return 0;
  }
  return run_autograder();
}